/*
   graphs > specials > tree > lowest common ancestor (LCA)
   difficulty: easy
   date: 10/Oct/2020
   problem: given a weighted tree, find the distance between 2 query vertices
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,ll>>> adj_list;

class sparse_table {
 private:
   vector<ll> A; int N;
   vector<vector<int>> table;

   int range_combination(int i, int j) {
      return A[i] < A[j]? i : j;
   }

   void build() {
      int P = (int)floor(log2(N));
      table.assign(P+1, vector<int>(N));

      for (int n = 0; n < N; n++) table[0][n] = n;
      
      for (int p = 1; p <= P; p++)
         for (int n = 0; n + (1<<p) <= N; n++) {
            table[p][n] = range_combination(
               table[p-1][n],
               table[p-1][n + (1<<(p-1))]
            );
         }
   }

 public:
   sparse_table() {}
   sparse_table(vector<ll> const &A) {
      this->A = A;
      N = (int)A.size();
      build();
   }

   int range_query(int l, int r) {
      int size = r-l+1;
      int p = (int)floor(log2(size));
      return range_combination(table[p][l], table[p][r - (1<<p) + 1]);
   }
};

class lca {
 private:
   vector<vector<pair<int,ll>>> adj_list; int V;

   int e;                   
   vector<ll> tour_depth;   
   vector<int> tour_vertex; 

   vector<ll> depth;   
   vector<int> last_e; 
   vector<bool> seen;

   sparse_table st;

   void process(int u, ll u_depth) {
      tour_vertex[e] = u;
      tour_depth[e] = u_depth;
      last_e[u] = e++;
   }

   void dfs(int u, ll u_depth = 0) {
      seen[u] = true;
      depth[u] = u_depth;
      process(u, u_depth);

      for (auto adj : this->adj_list[u]) {
         int v; ll w; tie(v, w) = adj;
         if (!seen[v]) {
            dfs(v, u_depth+w);
            process(u, u_depth);
         }
      }
   }

   void build(int root) {
      last_e.resize(V);
      depth.resize(V);

      e = 0;
      tour_depth.resize(2*V-1);
      tour_vertex.resize(2*V-1);

      seen.assign(V, false);
      dfs(root);

      st = sparse_table(tour_depth);
   }

 public:
   lca() {}
   lca(vector<vector<pair<int,ll>>> const &adj_list, int root = 0) {
      this->adj_list = adj_list;
      V = adj_list.size();
      build(root);
   }

   int query_lca(int u, int v) {
      int l = min(last_e[u], last_e[v]);
      int r = max(last_e[u], last_e[v]);
      return tour_vertex[st.range_query(l, r)];
   }

   ll query_dist(int u, int v) {
      return depth[u] + depth[v] - 2 * depth[query_lca(u,v)];
   }
};

int main() {
   int V; cin >> V;
   adj_list.assign(V, vector<pair<int,ll>>());
   for (int e = 0; e < V-1; e++) {
      int u, v; ll w; cin >> u >> v >> w;
      adj_list[u].push_back({v,w});
      adj_list[v].push_back({u,w});
   }

   lca l(adj_list);

   int Q; cin >> Q;
   while (Q--) {
      int u, v; cin >> u >> v;
      cout << l.query_dist(u, v) << endl;
   }
   return 0;
}