/*
   For efficient range queries on a dynamic array A of size N (frequently updated).
   Common range queries: min, max, sum, gcd.

   - Uma árvore binária completa com N vértices folhas tem 2*N-1 vértices e log2(N+1) níveis
*/
#include <bits/stdc++.h>
using namespace std;

class seg_tree {
 private:
   vector<int> A; int N;
   vector<int> bin_tree; // bin_tree[v]: resultado da consulta no intervalo (de A) associado

   int le(int v) { return (v << 1) + 1; } // filho à esq de v em bin_tree
   int ri(int v) { return (v << 1) + 2; } // filho à dir de v em bin_tree

   /* O(1) - change here to RMQ or RSQ */
   int range_combination(int a, int b) {
      return min(a, b);
   }

   /* O(N*log(N)) */
   void build(int v, int l, int r) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // v é nó folha
      if (l == r) { bin_tree[v] = A[l]; return; } 

      int mid = (l + r) / 2;
      build(le(v), l, mid+0);
      build(ri(v), mid+1, r);

      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   /* O(log2(N)) - consulta A[ql .. qr] */
   int range_query(int v, int l, int r, int ql, int qr) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] está completamente fora de [ql .. qr]
      if (ql > r || qr < l) return 1 << 30;
      // [l .. r] está completamente dentro de [ql .. qr]
      if (l >= ql && r <= qr) return bin_tree[v];

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int mid = (l + r) / 2;
      return range_combination(
         range_query(le(v), l, mid, ql, qr),
         range_query(ri(v), mid+1, r, ql, qr)
      );
   }

   /* O(log2(N)) - incrementa A[i] com diff */
   void point_update(int v, int l, int r, int i, int diff) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] não contém i
      if (i > r || i < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int mid = (l + r) / 2;
      point_update(le(v), l, mid+0, i, diff);
      point_update(ri(v), mid+1, r, i, diff);

      // na volta, após já ter atualizado os filhos do vértice v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   /* O(log2(N)) - incrementa A[ul .. ur] com diff */
   void range_update(int v, int l, int r, int ul, int ur, int diff) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      // [l .. r] está completamente fora de [ul .. ur]
      if (ul > r || ur < l) return;

      // v é nó folha
      if (l == r) { bin_tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int mid = (l + r) / 2;
      range_update(le(v), l, mid+0, ul, ur, diff);
      range_update(ri(v), mid+1, r, ul, ur, diff);

      // na volta, após já ter atualizado os filhos de v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

 public:
   seg_tree() {}
   seg_tree(vector<int> const &A) {
      this->A = A;
      N = (int)A.size();
      bin_tree.assign(4*N, 0);
      build(0, 0, N-1);
   }

   int range_query(int ql, int qr) {
      return range_query(0, 0, N-1, ql, qr);
   }

   void point_update(int i, int diff) {
      point_update(0, 0, N-1, i, diff);
   }

   void range_update(int ul, int ur, int diff) {
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