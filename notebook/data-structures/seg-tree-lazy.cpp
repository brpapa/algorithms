/*
   Lazy Segment Tree

   ---
   A operação range_update é preguiçosa, pois só atualiza de fato o bin_tree[v] com [l .. r] mais abrangente possível dentro de [ul .. ur], e apenas marca lazy[le(v)] e lazy[ri(v)] com o valor que eles devem ser atualizados quando forem consultados.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class lazy_seg_tree {
 private:
   vector<ll> A; int N;

   vector<ll> bin_tree; // bin_tree[v] = resultado da consulta no intervalo (de A) associado
   vector<ll> lazy;     // lazy[v] = valor de uma atualização pendente que precisa ser adicionado na sub-árvore enraizada por bin_tree[v] antes de qualquer consulta/atualização de v

   /* O(1) - RSQ (change here) */
   ll range_combination(ll a, ll b) {
      return a + b;
   }

   int le(int v) { return (v << 1) + 1; }
   int ri(int v) { return (v << 1) + 2; }

   /* O(N*log(N)) - constroi bin_tree */
   void build(int v, int l, int r) {
      // bin_tree[v] = resultado da consulta em A[l .. r]

      if (l == r) { bin_tree[v] = A[l]; return; } // v é nó folha

      int m = (l + r) / 2;
      build(le(v), l, m+0);
      build(ri(v), m+1, r);

      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }
 
   /* O(1) - se tem lazy[v], atualiza bin_tree[v] e o propaga aos seus filhos */
   void propagate_lazy(int v, int l, int r) {
      // FIXME se mudar range_query
      if (lazy[v] == 0) return;
      bin_tree[v] += (r-l+1) * lazy[v];

      // se v não é nó folha
      if (l != r) {
         lazy[le(v)] += lazy[v];
         lazy[ri(v)] += lazy[v];
      }
      lazy[v] = 0;
   }

 public:
   lazy_seg_tree(vector<ll> _A) {
      A = _A;
      N = (int)A.size();
      bin_tree.assign(4*N, 0);
      lazy.assign(4*N, 0);
      build(0, 0, N-1);
   }

   /* consulta A[ql .. qr] */
   ll range_query(int ql, int qr) { return range_query(0, 0, N-1, ql, qr); }
   ll range_query(int v, int l, int r, int ql, int qr) {
      // bin_tree[v] = resultado da consulta em A[l .. r]

      propagate_lazy(v, l, r);

      // [l .. r] está completamente fora de [ql .. qr]
      if (ql > r || qr < l) return 0ll; // FIXME se mudar range_query

      // [l .. r] está completamente dentro de [ql .. qr]
      if (l >= ql && r <= qr) return bin_tree[v];

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int m = (l + r) / 2;
      return range_combination(
         range_query(le(v), l, m+0, ql, qr),
         range_query(ri(v), m+1, r, ql, qr)
      );
   }

   /* incrementa A[ul .. ur] com diff */
   void range_update(int ul, int ur, ll diff) { range_update(0, 0, N-1, ul, ur, diff); }
   void range_update(int v, int l, int r, int ul, int ur, ll diff) {
      // bin_tree[v] = resultado da consulta em A[l .. r]

      propagate_lazy(v, l, r);

      // [l .. r] está completamente fora de [ul .. ur]
      if (ul > r || ur < l) return;

      // [l .. r] está completamente dentro de [ul .. ur] 
      if (l >= ul && r <= ur) { lazy[v] = diff; propagate_lazy(v, l, r); return; }

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int m = (l + r) / 2;
      range_update(le(v), l, m+0, ul, ur, diff);
      range_update(ri(v), m+1, r, ul, ur, diff);

      // na volta, após já ter atualizado os filhos do vértice v
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }
};

int main() {
   lazy_seg_tree st({ 1, 3, 5, 7, 9, 11 });
   cout << st.range_query(1, 3) << endl;
   st.range_update(1, 5, 10);
   cout << st.range_query(1, 3) << endl;
   return 0;
}