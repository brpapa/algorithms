/*
   Lowest Common Ancestor (LCA) with the eulerian tour method

   Motivação: dado uma rooted tree T(V, E), o LCA entre u e v é o vértice de maior nível que tem u e v como seus descendentes.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<int>> adj_list;

// answer for the index of the minimum value in a range of A
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
         for (int n = 0; n + (1<<p) <= N; n++) {
            table[p][n] = range_combination(
               table[p-1][n],
               table[p-1][n + (1<<(p-1))]
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
      return range_combination(table[p][l], table[p][r - (1<<p) + 1]);
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
      st = sparse_table(tour_depth);
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

/* e.g */
int main() {
   adj_list.assign(7, vector<int>());
   adj_list[0].push_back(1);
   adj_list[1].push_back(3);
   adj_list[0].push_back(2);
   adj_list[2].push_back(4);
   adj_list[4].push_back(6);
   adj_list[2].push_back(5);

   lca inst(adj_list);
   cout << inst.query_lca(3, 2) << endl;
   cout << inst.query_lca(4, 2) << endl;
   cout << inst.query_lca(6, 6) << endl;

   cout << inst.query_dist(3, 6) << endl;
   cout << inst.query_dist(5, 6) << endl;
   return 0;
}

// https://youtu.be/sD1IoalFomA?list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc
