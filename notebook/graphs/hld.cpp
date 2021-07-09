/*
   Motivation: given an connected tree G(V,V-1), perform the following queries:
      - query_path(u, v): get the sum of the weights of the edges on path from u to v.
      - update_path(u, v, x): increase the weights of the path from u to v with x.

   ---
   A ideia é decompor a árvore em ramos disjuntos (chains), para que as chains concatenas seja o array base de uma estrutura em range (como segment tree).

   Uma aresta u -> v é heavy, se size(v) > size(r) para todo irmão r de v.
   Ramos distintos são conectados por uma light edge (not heavy). O número de light edges em qualquer caminho da raiz até a folha é no máximo log2(V)

   ---
   Mude range_combination tanto em seg_tree como hld para o seu problema!

   ---
   Em ./notebook/assets/hld-chains.png, o array no canto inferior é arr da implementação (mas nesse caso wgt[v] = v), e as arestas em negrito são heavy edges (e o restante light edge).
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
class seg_tree {
 private:
   vector<T> A; int N;
   vector<T> bin_tree; // bin_tree[v] = resultado da consulta no intervalo (de A) associado

   int le(int v) { return (v << 1) + 1; } // filho à esq de v em bin_tree
   int ri(int v) { return (v << 1) + 2; } // filho à dir de v em bin_tree

   /* O(1) */
   T range_combination(T a, T b) {
      return a+b;
   }

   /* O(N*log(N)) */
   void build(int v, int l, int r) {
      // bin_tree[v] = resultado da consulta em A[l..r]

      // v é nó folha
      if (l == r) { bin_tree[v] = A[l]; return; } 

      int m = (l + r) / 2;
      build(le(v), l, m+0);
      build(ri(v), m+1, r);

      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

 public:
   seg_tree() {}

   /* O(N*log(N)) */
   seg_tree(vector<T> const &A) {
      this->A = A; N = (int)A.size();
      bin_tree.assign(4*N, 0);
      build(0, 0, N-1);
   }

   /* O(log2(N)) - consulta A[ql..qr] */
   T range_query(int ql, int qr) { return rq(0, 0, N-1, ql, qr); }
   T rq(int v, int l, int r, int ql, int qr) {
      // bin_tree[v] = resultado da consulta em A[l..r]

      // [l..r] está completamente fora de [ql..qr]
      if (ql > r || qr < l) return 0;
      // [l..r] está completamente dentro de [ql..qr]
      if (l >= ql && r <= qr) return bin_tree[v];

      // [l..r] está parcialmente dentro e parcialmente fora de [ql..qr]
      int m = (l + r) / 2;
      return range_combination(
         rq(le(v), l, m+0, ql, qr),
         rq(ri(v), m+1, r, ql, qr)
      );
   }

   /* O(log2(N)) - incrementa A[i] com x */
   void point_update(int i, T x) { pu(0, 0, N-1, i, x); }
   void pu(int v, int l, int r, int i, T x) {
      // bin_tree[v] = resultado da consulta em A[l..r]

      // [l..r] não contém i
      if (i > r || i < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += x, A[l] += x; return; }

      // v não é nó folha
      int m = (l + r) / 2;
      pu(le(v), l, m+0, i, x);
      pu(ri(v), m+1, r, i, x);

      // na volta, após já ter atualizado os filhos do vértice v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   /* O(log2(N)) - incrementa A[ul..ur] com x */
   void range_update(int ul, int ur, T x) { ru(0, 0, N-1, ul, ur, x); }
   void ru(int v, int l, int r, int ul, int ur, T x) {
      // bin_tree[v] = resultado da consulta em A[l..r]

      // [l..r] está completamente fora de [ul..ur]
      if (ul > r || ur < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += x, A[l] += x; return; }

      // v não é nó folha
      int m = (l + r) / 2;
      ru(le(v), l, m+0, ul, ur, x);
      ru(ri(v), m+1, r, ul, ur, x);

      // na volta, após já ter atualizado os filhos de v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }
};

class hld {
 private:
   vector<vector<pair<int,ll>>> adj_list; int V; // adj_list[u] = {{v, w}, ...}

   vector<int> size; // size[u] = number of vertices of the u-rooted subtree 
   vector<int> parent; // parent[v] = parent of vertex v
   vector<int> head; // head[u] = head vertex of the chain which vertex u belongs to; if head[u] = u, u is the head of his chain.

   vector<ll> wgt; // wgt[v] = weight of edge u -> v

   seg_tree<ll> st;
   vector<ll> arr; // base array of the segment tree, which is a convenient wgt[v] order, for every vertex v; onde vértices de mesmas chains são continuos, e os vértices de uma chain ancestral à outra chain sempre aparecem antes dos vértices dessa outra chain
   vector<int> arr_rev; // arr_rev[u] = index of the wgt[u] in arr

   /* O(1) */
   ll range_combination(ll a, ll b) {
      return a+b;
   }

   /* O(V) - mantains the heavy edge on begin of the adj_list[u], for every vertex u */
   void dfs_init(int u, int u_parent = -1) {
      size[u] = 1;
      for (auto &adj : adj_list[u]) {
         int v; ll w; tie(v, w) = adj;
         if (v != u_parent) {
            dfs_init(v, u);
            size[u] += size[v];
            if (size[v] > size[adj_list[u][0].first])
               swap(adj, adj_list[u][0]);
         }
      }
   }

   /* O(V) - fills arr, arr_rev and head */
   void dfs_build(int u, int u_parent = -1) {
      arr.push_back(wgt[u]);
      arr_rev[u] = arr.size()-1;

      for (auto adj : adj_list[u]) {
         int v; ll w; tie(v, w) = adj;
         if (v != u_parent) {
            parent[v] = u;
            wgt[v] = w;
            head[v] = (adj == adj_list[u][0]? head[u] : v); // creates a new chain for every light edge
            dfs_build(v, u);
         }
      }
   }
   
 public:
   /* O(V) */
   hld(vector<vector<pair<int,ll>>> const &adj_list, int root = 0) {
      this->adj_list = adj_list; V = adj_list.size();
      size.assign(V, -1); parent.assign(V, -1); head.assign(V, -1); arr_rev.assign(V, -1);
      wgt.assign(V, 0); // note that wgt[root] will not be updated

      dfs_init(root);
      head[root] = root; dfs_build(root);

      st = seg_tree<ll>(arr);
   }

   /* O(log^2(V)) - returns the sum of edges weight on path from u to v */
   ll query_path(int u, int v) {
      if (u == v) return 0;
      if (arr_rev[u] > arr_rev[v]) swap(u, v); // ensures that u is before v in arr, so the chain of u is ancentral of the chain of v

      if (head[u] == head[v])
         return st.range_query(arr_rev[u]+1, arr_rev[v]);

      return range_combination(
         st.range_query(arr_rev[head[v]], arr_rev[v]), 
         query_path(parent[head[v]], u)
      );
   }

   /* O(log^2(V)) - increase the weights of path from u to v with x */
   void update_path(int u, int v, ll x) {
      if (u == v) return;
      if (arr_rev[u] > arr_rev[v]) swap(u, v); // ensures that u is before v in arr, so the chain of u is ancentral of the chain of v

      if (head[u] == head[v])
         return (void) st.range_update(arr_rev[u]+1, arr_rev[v], x);

      st.range_update(arr_rev[head[v]], arr_rev[v], x);
      update_path(parent[head[v]], u, x);
   }

   /* O(log(V)) */
   int lca(int u, int v) {
      if (arr_rev[u] > arr_rev[v]) swap(u, v);
      return head[u] == head[v]? u : lca(parent[head[v]], u);
   }

   /* O(log(V) - query the u-rooted subtree */
   ll query_subtree(int u) {
      if (size[u] == 1) return 0;
      return st.range_query(arr_rev[u]+1, arr_rev[u]+size[u]-1);
   }

   /* O(log(V) - update the u-rooted subtree */
   void update_subtree(int u, ll x) {
      if (size[u] == 1) return;
      st.range_update(arr_rev[u]+1, arr_rev[u]+size[u]-1, x);
   }
};


int main() {
   vector<vector<pair<int,ll>>> adj_list = {
      {},
      {{2, 1}, {3, 1}, {4, 1}},
      {{5, 1}, {6, 1}, {7, 1}, {8, 1}},
      {},
      {{9, 1}},
      {{10, 1}},
      {},
      {{11, 1}, {12, 1}},
      {{13, 1}, {14, 1}},
      {},
      {},
      {{15, 1}},
      {{16, 1}, {17, 1}},
      {{18, 1}},
      {{19, 1}, {20, 1}},
      {},
      {},
      {},
      {},
      {{21, 1}},
      {},
      {}
   };
   
   hld h(adj_list, 1);
   cout << h.query_path(1, 18) << endl;
   cout << h.query_subtree(8) << endl;
   h.update_path(15, 14, 1);
   cout << h.query_path(2, 14) << endl;
   return 0;
}