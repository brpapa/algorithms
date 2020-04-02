/*
   searching > segment tree > lazy propagation
   difficulty: medium
   date: 13/Mar/2020 
   solution: build a segment tree for RSQ, but store an array of size 9 in tree[v], where tree[v][n] indicates the frequency that each note n appears in that interval
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 100100
using namespace std;

int tree[3*MAX_N][9];
int lazy[3*MAX_N];

void build(int v, int l, int r) {
   if (l == r) {
      tree[v][1] = 1;
      return; 
   }

   int mid = (l+r)/2;
   build(2*v+1, l, mid+0);
   build(2*v+2, mid+1, r);

   tree[v][1] = tree[2*v+1][1] + tree[2*v+2][1];
}

vector<int> tmp(9);
void propagateLazy(int v, int l, int r) {
   if (lazy[v] == 0) return;

   // desloca tree[v] para a direita lazy[v] vezes
   for (int n = 0; n < 9; n++) tmp[(n+lazy[v])%9] = tree[v][n];
   for (int n = 0; n < 9; n++) tree[v][n] = tmp[n];

   if (l != r) {
      lazy[2*v+1] += lazy[v];
      lazy[2*v+2] += lazy[v];
   }
   lazy[v] = 0;
}

vector<int> ansQuery;
void rangeQuery(int v, int l, int r, int ql, int qr) {
   if (v == 0) ansQuery.assign(9, 0);
   propagateLazy(v, l, r);

   if (l > qr || r < ql)   return;
   if (l >= ql && r <= qr) {
      for (int n = 0; n < 9; n++) ansQuery[n] += tree[v][n];
      return;
   }

   int mid = (l+r)/2;
   rangeQuery(2*v+1, l, mid+0, ql, qr);
   rangeQuery(2*v+2, mid+1, r, ql, qr);
}

void rangeUpdate(int v, int l, int r, int ul, int ur, int diff) {
   propagateLazy(v, l, r);
   if (l > ur || r < ul) return;

   if (l >= ul && r <= ur) {
      lazy[v] = diff; propagateLazy(v, l, r);
      return;
   }

   int mid = (l+r)/2;
   rangeUpdate(2*v+1, l, mid+0, ul, ur, diff);
   rangeUpdate(2*v+2, mid+1, r, ul, ur, diff);

   for (int n = 0; n < 9; n++) tree[v][n] = tree[2*v+1][n] + tree[2*v+2][n];
}

int main() {
   int N, Q; cin >> N >> Q;

   memset(tree, 0, sizeof tree);
   memset(lazy, 0, sizeof lazy);
   build(0, 0, N-1);

   while (Q--) {
      int ql, qr; cin >> ql >> qr;
      rangeQuery(0, 0, N-1, ql, qr);

      // procura pela nota n mais frequente em ansQuery
      int freqMax = -1, nMax = -1;
      for (int n = 8; n >= 0; n--)
         if (ansQuery[n] > freqMax) {
            freqMax = ansQuery[n];
            nMax = n;
         }

      rangeUpdate(0, 0, N-1, ql, qr, nMax);
   }
   for (int i = 0; i < N; i++) {
      rangeQuery(0, 0, N-1, i, i);
      for (int n = 0; n < 9; n++)
         if (ansQuery[n]) {
            cout << n << endl;
            break;
         }
   }
   return 0;
}