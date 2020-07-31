#include <bits/stdc++.h>
using namespace std;

/*
   For efficient range queries on a dynamic array A (frequently updated).

   - Uma árvore binária completa com N vértices folhas tem 2*N-1 vértices
   - Uma árvore binária completa com N vértices folhas tem log2(N+1) níveis
*/

// para consultar RMQ
class SegTree {
 private:
   vector<int> A;
   vector<int> bin_tree; // bin_tree[v]: resultado da consulta no intervalo (de A) associado

   int le(int v) { return (v << 1) + 1; } // filho à esq de v em bin_tree
   int ri(int v) { return (v << 1) + 2; } // filho à dir de v em bin_tree

   /* O(N*log(N)) - constroi bin_tree */
   void build(int v, int l, int r) {
      // bin_tree[v]: resultado da consulta em A[l .. r]

      if (l == r) { bin_tree[v] = A[l]; return; } // v é nó folha

      int mid = (l + r) / 2;
      build(le(v), l, mid+0);
      build(ri(v), mid+1, r);

      bin_tree[v] = min(bin_tree[le(v)], bin_tree[ri(v)]);
      // bin_tree[v] = bin_tree[le(v)] + bin_tree[ri(v)];
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
      return min(range_query(le(v), l, mid, ql, qr), range_query(ri(v), mid+1, r, ql, qr));
      // return range_query(le(v), l, mid, ql, qr) + range_query(ri(v), mid+1, r, ql, qr);
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
      bin_tree[v] = min(bin_tree[le(v)], bin_tree[ri(v)]);
      // bin_tree[v] = bin_tree[le(v)] + bin_tree[ri(v)];
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
      bin_tree[v] = min(bin_tree[le(v)], bin_tree[ri(v)]);
      // bin_tree[v] = bin_tree[le(v)] + bin_tree[ri(v)];
   }

 public:
   SegTree(vector<int> _A) {
      A = _A;
      bin_tree.assign(3*A.size(), 0);
      build(0, 0, A.size()-1);
   }

   int range_query(int ql, int qr) {
      return range_query(0, 0, A.size()-1, ql, qr);
   }

   void point_update(int i, int diff) {
      point_update(0, 0, A.size()-1, i, diff);
   }

   void range_update(int ul, int ur, int diff) {
      range_update(0, 0, A.size()-1, ul, ur, diff);
   }
};

/* e.g */
int main() {
   SegTree st({ 1, 3, 5, 7, 9, 11 });
   cout << st.range_query(1, 3) << endl;
   st.range_update(1, 5, 10);
   cout << st.range_query(1, 3) << endl;
   return 0;
}