/*
   For efficient range queries on a dynamic array A of size N (frequently updated).
   Common range queries: min, max, sum, gcd.

   - Uma árvore binária completa com N vértices folhas tem 2*N-1 vértices e log2(N+1) níveis
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class seg_tree {
 private:
   vector<ll> A; int N;
   vector<ll> bin_tree; // bin_tree[v]: resultado da consulta no intervalo (de A) associado

   int le(int v) { return (v << 1) + 1; } // filho à esq de v em bin_tree
   int ri(int v) { return (v << 1) + 2; } // filho à dir de v em bin_tree

   /* O(1) - RMQ (change here) */
   ll range_combination(ll a, ll b) {
      return min(a, b);
   }

   /* O(N*log(N)) */
   void build(int v, int l, int r) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // v é nó folha
      if (l == r) { bin_tree[v] = A[l]; return; } 

      int m = (l + r) / 2;
      build(le(v), l, m+0);
      build(ri(v), m+1, r);

      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   /* O(log2(N)) - consulta A[ql .. qr] */
   ll range_query(int v, int l, int r, int ql, int qr) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] está completamente fora de [ql .. qr]
      if (ql > r || qr < l) return INT_MAX; // FIXME se mudar range_query
      // [l .. r] está completamente dentro de [ql .. qr]
      if (l >= ql && r <= qr) return bin_tree[v];

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int m = (l + r) / 2;
      return range_combination(
         range_query(le(v), l, m+0, ql, qr),
         range_query(ri(v), m+1, r, ql, qr)
      );
   }

   /* O(log2(N)) - incrementa A[i] com diff */
   void point_update(int v, int l, int r, int i, ll diff) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] não contém i
      if (i > r || i < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int m = (l + r) / 2;
      point_update(le(v), l, m+0, i, diff);
      point_update(ri(v), m+1, r, i, diff);

      // na volta, após já ter atualizado os filhos do vértice v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   /* O(log2(N)) - incrementa A[ul .. ur] com diff */
   void range_update(int v, int l, int r, int ul, int ur, ll diff) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] está completamente fora de [ul .. ur]
      if (ul > r || ur < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int m = (l + r) / 2;
      range_update(le(v), l, m+0, ul, ur, diff);
      range_update(ri(v), m+1, r, ul, ur, diff);

      // na volta, após já ter atualizado os filhos de v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

 public:
   seg_tree() {}
   seg_tree(vector<ll> const &A) {
      this->A = A;
      N = (int)A.size();
      bin_tree.assign(4*N, 0);
      build(0, 0, N-1);
   }

   ll range_query(int ql, int qr) {
      return range_query(0, 0, N-1, ql, qr);
   }

   void point_update(int i, ll diff) {
      point_update(0, 0, N-1, i, diff);
   }

   void range_update(int ul, int ur, ll diff) {
      range_update(0, 0, N-1, ul, ur, diff);
   }
};

/* e.g */
int main() {
   seg_tree st({ 1, 3, 5, 7, 9, 11 });
   cout << st.range_query(1, 3) << endl;
   st.range_update(1, 5, 10);
   cout << st.range_query(1, 3) << endl;
   return 0;
}