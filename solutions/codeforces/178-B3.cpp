/*
   graphs > traversal > bridges or articulation points
   difficulty: hard
   date: 02/Aug/2020
   problem: given an undirected graph, count how many bridge edges exists between 2 query vertices
   hint: group the vertices connected by non-bridge edge during dfs; generate a tree considering each group as a vertice, and using only the bridge edges; find the distance between 2 query vertices of that tree with LCA in O(1)
   by: @brnpapa
*/
#include <bits/stdc++.h>
#define pow2(i) (1 << (i)) // = 2^i
using namespace std;

class ufds {
 private:
   vector<int> parent; // parent[n]: pai do elemento n
   vector<int> size;   // size[n]: tamanho do conjunto identificado por n
   int qty_disjoint_sets;

 public:
   ufds() {}
   ufds(int N) {
      parent.resize(N);
      size.assign(N, 1);
      qty_disjoint_sets = N;
      
      // inicialmente, há N conjuntos disjuntos
      for (int n = 0; n < N; n++) parent[n] = n;
   }

   /* O(1) - retorna a raiz do conjunto de n */
   int find_set(int n) {
      if (parent[n] == n) return n;

      // path compression durante a busca
      return parent[n] = find_set(parent[n]); 
   }
	
   /* O(1) - os conjuntos de n e de m são os mesmos? */
   bool is_same_set(int n, int m) {
      return find_set(n) == find_set(m);
   }

	/* O(1) - conecta os conjuntos de n e de m */
   void union_sets(int n, int m) {
      int n_id = find_set(n);
      int m_id = find_set(m);

      // union by size: conecta a menor árvore à maior árvore
      if (!is_same_set(n_id, m_id)) {
         if (size[n_id] > size[m_id])
            swap(n_id, m_id);

         parent[n_id] = m_id;
         size[m_id] += size[n_id];

         qty_disjoint_sets--;
      }
   }

   /* O(1) - tamanho do conjunto de n */
   int set_size(int n) {
      return size[find_set(n)];
   }

   /* O(1) - quantidade de conjuntos disjuntos */
   int count() {
      return qty_disjoint_sets;
   }
};

class sparse_table {
 private:
   vector<int> A; int N;
   vector<vector<int>> table; // table[p][n]: answer for the range [n, n+2^p) (size 2^p) in A

   /* O(1) */
   int range_combination(int i, int j) {
      return A[i] < A[j]? i : j;
   }

   /* O(N * log(N)) */
   void build() {
      int P = (int)floor(log2(N));
      table.assign(P+1, vector<int>(N));

      for (int n = 0; n < N; n++) table[0][n] = n;
      
      for (int p = 1; p <= P; p++)
         for (int n = 0; n+pow2(p) <= N; n++) {
            table[p][n] = range_combination(
               table[p-1][n],
               table[p-1][n+pow2(p-1)]
            );
         }
   }

 public:
   sparse_table() {}
   sparse_table(vector<int> const &A) {
      this->A = A;
      N = (int)A.size();
      build();
   }

   /* O(1) - answer for range query [l, r] in A */
   int range_query(int l, int r) {
      int size = r-l+1;
      int p = (int)floor(log2(size));
      return range_combination(table[p][l], table[p][r-pow2(p)+1]);
   }
};

class lca {
 private:
   vector<vector<int>> adj_list; int V;

   int e;                   // eulerian tour timer
   vector<int> tour_depth;  // tour_depth[e]: nível em relação à root do e-ésimo vértice visitado pelo eulerian tour
   vector<int> tour_vertex; // tour_vertex[e]: e-ésimo vértice visitado pelo eulerian tour

   vector<int> depth;  // depth[u]: nível de u em relação à root
   vector<int> last_e; // last_e[u]: último e do vértice u (inverse map of tour_vertex)
   vector<bool> seen;

   sparse_table st;

   /* O(1) */
   void process(int u, int u_depth) {
      tour_vertex[e] = u;
      tour_depth[e] = u_depth;
      last_e[u] = e++;
   }

   /* O(V) - eulerian tour */
   void dfs(int u, int u_depth = 0) {
      seen[u] = true;
      depth[u] = u_depth;
      process(u, u_depth);

      for (int v : this->adj_list[u])
         if (!seen[v]) {
            dfs(v, u_depth+1);
            process(u, u_depth);
         }
   }

   /* O(V * log(V)) */
   void build(int root) {
      last_e.resize(V);
      depth.resize(V);

      e = 0;
      tour_depth.resize(2*V-1);
      tour_vertex.resize(2*V-1);

      seen.assign(V, false);

      dfs(root);
      st = sparse_table(vector<int>(tour_depth.begin(), tour_depth.end()));
   }

 public:
   lca() {}
   lca(vector<vector<int>> const &adj_list, int root = 0) {
      this->adj_list = adj_list;
      V = adj_list.size();
      build(root);
   }

   /* O(1) */
   int query_lca(int u, int v) {
      // recover the vertex with minimum depth between u and v in eulerian tour
      int l = min(last_e[u], last_e[v]);
      int r = max(last_e[u], last_e[v]);
      return tour_vertex[st.range_query(l, r)];
   }

   /* O(1) */
   int query_dist(int u, int v) {
      return depth[u] + depth[v] - 2 * depth[query_lca(u,v)];
   }
};

vector<vector<int>> given_adj_list;
vector<vector<int>> new_adj_list; // árvore só com as arestas ponte
ufds sets; // conjuntos dos vértices conectados por arestas não ponte

vector<pair<int, int>> bridges;
const int UNVISITED = -1;
vector<int> order;
vector<int> low;
vector<int> parent;
int count_order;

/* O(V+E) - encontra as arestas pontes, e une os vértices conectados por aresta não-ponte */
void dfs(int u) {
   low[u] = order[u] = count_order++;

   // para cada aresta u -> v
   for (int v : given_adj_list[u]) {
      if (order[v] == UNVISITED) {
         parent[v] = u;
         dfs(v);

         // callback propagation
         low[u] = min(low[u], low[v]);
         if (order[u] < low[v])
            bridges.push_back(make_pair(u, v));
         else
            sets.union_sets(u, v);
      }
      else if (v != parent[u])
         low[u] = min(low[u], low[v]);
   }
}

int main() {
   int V, E; cin >> V >> E;
   given_adj_list.assign(V, vector<int>());
   for (int _ = 0; _ < E; _++) {
      int u, v; cin >> u >> v; u--; v--;
      given_adj_list[u].push_back(v);
      given_adj_list[v].push_back(u);
   }

   sets = ufds(V);

   count_order = 0; order.assign(V, -1); low.assign(V, -1); parent.assign(V, -1);
   dfs(0);

   int root = -1;
   new_adj_list.assign(V, vector<int>());
   for (auto bridge : bridges) {
      int u = sets.find_set(bridge.first);
      int v = sets.find_set(bridge.second);
      new_adj_list[u].push_back(v);
      new_adj_list[v].push_back(u);
      root = u;
   }

   lca l;
   if (root != -1) l = lca(new_adj_list, root);
   
   int Q; cin >> Q;
   while (Q--) {
      int u, v; cin >> u >> v; u--; v--;
      if (root == -1) cout << "0" << endl;
      else cout << l.query_dist(sets.find_set(u), sets.find_set(v)) << endl;
   }
   return 0;
}