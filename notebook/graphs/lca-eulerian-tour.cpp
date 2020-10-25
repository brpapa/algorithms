/*
   Lowest Common Ancestor (LCA) with the eulerian tour method

   Motivação: dado uma positive-weighted rooted tree G(V, V-1), o LCA entre u e v é o vértice de maior nível que tem u e v como seus descendentes.

   ---
   https://youtu.be/sD1IoalFomA?list=PLDV1Zeh2NRsDfGc8rbQ0_58oEZQVtvoIc
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
vector<vector<pair<int,ll>>> adj_list; // adj_list[u]: {{v, w}, ...}

// answer for the index of the minimum value in a range of A
class sparse_table {
 private:
   vector<ll> A; int N;
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
   sparse_table(vector<ll> const &A) {
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
   vector<vector<pair<int,ll>>> adj_list; int V;

   int e;                   // eulerian tour timer
   vector<ll> tour_depth;   // tour_depth[e]: nível em relação à root do e-ésimo vértice visitado pelo eulerian tour
   vector<int> tour_vertex; // tour_vertex[e]: e-ésimo vértice visitado pelo eulerian tour

   vector<ll> depth;   // depth[u]: nível de u em relação à root
   vector<int> last_e; // last_e[u]: último e do vértice u (inverse map of tour_vertex)
   vector<bool> seen;

   sparse_table st;

   /* O(1) */
   void process(int u, ll u_depth) {
      tour_vertex[e] = u;
      tour_depth[e] = u_depth;
      last_e[u] = e;
      e++;
   }

   /* O(V) - eulerian tour */
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
   lca(vector<vector<pair<int,ll>>> const &adj_list, int root = 0) {
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
   ll query_dist(int u, int v) {
      return depth[u] + depth[v] - 2 * depth[query_lca(u,v)];
   }
};

/* e.g */
int main() {
   adj_list.assign(7, vector<pair<int,ll>>());
   adj_list[0].push_back({1,1});
   adj_list[1].push_back({3,1});
   adj_list[0].push_back({2,1});
   adj_list[2].push_back({4,1});
   adj_list[4].push_back({6,1});
   adj_list[2].push_back({5,1});

   lca l(adj_list);
   cout << l.query_lca(3, 2) << endl;
   cout << l.query_lca(4, 2) << endl;
   cout << l.query_lca(6, 6) << endl;

   cout << l.query_dist(3, 6) << endl;
   cout << l.query_dist(5, 6) << endl;
   return 0;
}
