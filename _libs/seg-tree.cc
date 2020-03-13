#include <iostream>
#include <vector>
#define INF (1 << 30)
using namespace std;

struct SegTree {
   const bool RMQ = 0, RSQ = 1; //! setar um ou outro

   vector<int> A;
   vector<int> tree; // tree[v]: resultado da consulta no intervalo (de A) associado

   int le(int v) { return (v << 1) + 1; } // filho à esq de v em tree
   int ri(int v) { return (v << 1) + 2; } // filho à dir de v em tree

   SegTree(vector<int> _A) {
      A = _A;
      tree.assign(3*A.size(), 0);
      build(0, 0, A.size()-1);
   }

   // constroi tree (O(N.log(N)))
   void build(int v, int l, int r) {
      // tree[v]: resultado da consulta em A[l .. r]

      if (l == r) { tree[v] = A[l]; return; } // v é nó folha

      int mid = (l + r) / 2;
      build(le(v), l, mid+0);
      build(ri(v), mid+1, r);

      if (RMQ) tree[v] = min(tree[le(v)], tree[ri(v)]);
      if (RSQ) tree[v] = tree[le(v)] + tree[ri(v)];
   }

   // consulta A[ql .. qr] (O(2*log2(N)) = O(log(N)))
   int rangeQuery(int v, int l, int r, int ql, int qr) {
      // tree[v]: resultado da consulta em A[l .. r]

      if (ql > r || qr < l)   // [l .. r] está completamente fora de [ql .. qr]
         return RMQ? INF : 0;
      if (l >= ql && r <= qr) // [l .. r] está completamente dentro de [ql .. qr]
         return tree[v];

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int mid = (l + r) / 2;
      if (RMQ) return min(rangeQuery(le(v), l, mid, ql, qr), rangeQuery(ri(v), mid+1, r, ql, qr));
      if (RSQ) return rangeQuery(le(v), l, mid, ql, qr) + rangeQuery(ri(v), mid+1, r, ql, qr);
   }
   int rangeQuery(int ql, int qr) { return rangeQuery(0, 0, A.size()-1, ql, qr); }

   // incrementa A[i] com diff (O(log2(N)) = O(log(N))
   void pointUpdate(int v, int l, int r, int i, int diff) {
      // tree[v]: resultado da consulta em A[l .. r]

      if (i > r || i < l) // [l .. r] não contém i
         return;

      // v é nó folha
      if (l == r) { tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int mid = (l + r) / 2;
      pointUpdate(le(v), l, mid+0, i, diff);
      pointUpdate(ri(v), mid+1, r, i, diff);

      // na volta, após já ter atualizado os filhos do vértice v
      if (RMQ) tree[v] = min(tree[le(v)], tree[ri(v)]);
      if (RSQ) tree[v] = tree[le(v)] + tree[ri(v)];
   }
   void pointUpdate(int i, int diff) { pointUpdate(0, 0, A.size()-1, i, diff); }


   // incrementa A[ul .. ur] com diff (O(2*log2(N)) = O(log(N)))
   void rangeUpdate(int v, int l, int r, int ul, int ur, int diff) {
      // tree[v]: resultado da consulta em A[l .. r]

      if (ul > r || ur < l) // [l .. r] está completamente fora de [ul .. ur]
         return;

      // v é nó folha
      if (l == r) { tree[v] += diff, A[l] += diff; return; }

      // v não é nó folha
      int mid = (l + r) / 2;
      rangeUpdate(le(v), l, mid+0, ul, ur, diff);
      rangeUpdate(ri(v), mid+1, r, ul, ur, diff);

      // na volta, após já ter atualizado os filhos de v
      if (RMQ) tree[v] = min(tree[le(v)], tree[ri(v)]);
      if (RSQ) tree[v] = tree[le(v)] + tree[ri(v)];
   }
   void rangeUpdate(int ul, int ur, int diff) { rangeUpdate(0, 0, A.size()-1, ul, ur, diff); }
};

struct LazySegTree {
   vector<int> A;

   // a operação rangeUpdate é preguiçosa, pois só atualiza de fato o tree[v] com [l .. r] mais abrangente possível dentro de [ul .. ur], e apenas marca lazy[le(v)] e lazy[ri(v)] com o valor que eles devem ser atualizados quando forem consultados

   vector<int> tree; // tree[v]: resultado da consulta no intervalo (de A) associado
   vector<int> lazy; // lazy[v]: valor de uma atualização pendente que precisa ser adicionado em tree[v] antes de qualquer consulta/atualização nele

   int le(int v) { return (v << 1) + 1; }
   int ri(int v) { return (v << 1) + 2; }

   LazySegTree(vector<int> _A) {
      A = _A;
      tree.assign(3*A.size(), 0);
      lazy.assign(3*A.size(), 0);
      build(0, 0, A.size()-1);
   }

   // constroi tree (O(N.log(N)))
   void build(int v, int l, int r) {
      // tree[v]: resultado da consulta em A[l .. r]

      if (l == r) { tree[v] = A[l]; return; } // v é nó folha

      int mid = (l + r) / 2;
      build(le(v), l, mid+0);
      build(ri(v), mid+1, r);

      tree[v] = tree[le(v)] + tree[ri(v)];
   }

   // se tem lazy[v], atualiza tree[v] e o propaga aos seus filhos
   void propagateLazy(int v, int l, int r) {
      if (lazy[v] == 0) return;
      tree[v] += (r-l+1) * lazy[v];

      if (l != r) {
         lazy[le(v)] += lazy[v];
         lazy[ri(v)] += lazy[v];
      }
      lazy[v] = 0;
   }

   // consulta A[ql .. qr]
   int rangeQuery(int v, int l, int r, int ql, int qr) {
      // tree[v]: resultado da consulta em A[l .. r]

      propagateLazy(v, l, r);

      // [l .. r] está completamente fora de [ql .. qr]
      if (ql > r || qr < l) return 0;

      // [l .. r] está completamente dentro de [ql .. qr]
      if (l >= ql && r <= qr) return tree[v];

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int mid = (l + r) / 2;
      return rangeQuery(le(v), l, mid, ql, qr) + rangeQuery(ri(v), mid+1, r, ql, qr);
   }
   int rangeQuery(int ql, int qr) { return rangeQuery(0, 0, A.size()-1, ql, qr); }

   // incrementa A[ul .. ur] com diff
   void rangeUpdate(int v, int l, int r, int ul, int ur, int diff) {
      // tree[v]: resultado da consulta em A[l .. r]

      propagateLazy(v, l, r);

      // [l .. r] está completamente fora de [ul .. ur]
      if (ul > r || ur < l) return;

      // [l .. r] está completamente dentro de [ul .. ur] 
      if (l >= ul && r <= ur) {
         lazy[v] = diff; propagateLazy(v, l, r);
         return; // note que não desce para le(v) nem re(v)
      }

      // [l .. r] está parcialmente dentro e parcialmente fora de [ql .. qr]
      int mid = (l + r) / 2;
      rangeUpdate(le(v), l, mid+0, ul, ur, diff);
      rangeUpdate(ri(v), mid+1, r, ul, ur, diff);

      // na volta, após já ter atualizado os filhos do vértice v
      tree[v] = tree[le(v)] + tree[ri(v)];
   }
   void rangeUpdate(int ul, int ur, int diff) { rangeUpdate(0, 0, A.size()-1, ul, ur, diff); }
};

int main() {
   LazySegTree st({ 1, 3, 5, 7, 9, 11 });
   cout << st.rangeQuery(1, 3) << endl;
   st.rangeUpdate(1, 5, 10);
   cout << st.rangeQuery(1, 3) << endl;
}
