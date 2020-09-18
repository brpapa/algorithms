/*
   searching > segment tree > lazy propagation
   difficulty: medium
   date: 12/Mar/2020 
   hint: build a segment tree for RSQ, but keep in lazy[v] the type of pending operation to be performed in that interval of A
   by: @brpapa
*/
#include <iostream>
#include <vector>
using namespace std;

#define NONE ' '
#define SET_1 'F'
#define SET_0 'E'
#define TOGGLE 'I'

vector<int> A, bin_tree;
vector<char> lazy;

int le(int v) { return (v << 1) + 1; }
int ri(int v) { return (v << 1) + 2; }

void build(int v, int l, int r) {   
   if (l == r) { bin_tree[v] = A[l]; return; }

   int mid = (l + r) / 2;
   build(le(v), l, mid + 0);
   build(ri(v), mid + 1, r);

   bin_tree[v] = bin_tree[le(v)] + bin_tree[ri(v)];
}

char inverse(char c) {
   if (c == SET_1)  return SET_0;
   if (c == SET_0)  return SET_1;
   if (c == TOGGLE) return NONE;
   if (c == NONE)   return TOGGLE;
}

void propagate_lazy(int v, int l, int r) {
   if (lazy[v] == NONE)   return;
   if (lazy[v] == SET_1)  bin_tree[v] = (r-l+1) * 1;            // A[l..r] = 1
   if (lazy[v] == SET_0)  bin_tree[v] = 0;                      // A[l..r] = 0
   if (lazy[v] == TOGGLE) bin_tree[v] = (r-l+1) - bin_tree[v];  // inverte A[l..r]

   if (l != r) {
      if (lazy[v] == TOGGLE) {
         lazy[le(v)] = inverse(lazy[le(v)]);
         lazy[ri(v)] = inverse(lazy[ri(v)]);
      }
      else lazy[le(v)] = lazy[ri(v)] = lazy[v];
   }
   lazy[v] = NONE;
}

int range_query(int v, int l, int r, int ql, int qr) {   
   propagate_lazy(v, l, r);

   if (ql > r || qr < l)   return 0;
   if (l >= ql && r <= qr) return bin_tree[v];

   int mid = (l + r) / 2;
   return range_query(le(v), l, mid, ql, qr) + range_query(ri(v), mid + 1, r, ql, qr);
}

void range_update(int v, int l, int r, int ul, int ur, char op) {   
   propagate_lazy(v, l, r);

   if (ul > r || ur < l) return;
   if (l >= ul && r <= ur) { lazy[v] = op; propagate_lazy(v, l, r); return; }

   int mid = (l + r) / 2;
   range_update(le(v), l, mid + 0, ul, ur, op);
   range_update(ri(v), mid + 1, r, ul, ur, op);

   bin_tree[v] = bin_tree[le(v)] + bin_tree[ri(v)];
}

int main() {
   int T, t = 0; cin >> T;
   while (T--) {
      A.clear();

      int M; cin >> M;
      while (M--) {
         int F; string s; cin >> F >> s;
         while (F--) for (char c : s) A.push_back(c == '1'? 1:0);
      }

      bin_tree.assign(3 * A.size(), 0);
      lazy.assign(3 * A.size(), NONE);
      build(0, 0, A.size()-1);

      printf("Case %d:\n", ++t);
      int Q, q = 0; cin >> Q;
      while (Q--) {
         char c; int l, r; cin >> c >> l >> r;

         if (c =='S') printf("Q%d: %d\n", ++q, range_query(0, 0, A.size()-1, l, r));
         else         range_update(0, 0, A.size()-1, l, r, c);
      }
   }
   return 0;
}