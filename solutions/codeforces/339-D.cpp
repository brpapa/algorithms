/*
   searching > segment tree
   difficulty: easy
   date: 07/Dec/2019 
   by: @brpapa
*/
#include <cmath>
#include <iostream>
#include <vector>
#define MAX_N 132000 // pow(2, 17)
using namespace std;

int A[MAX_N];
int N;

vector<int> tree;
int le(int v) { return 2 * v + 1; };
int ri(int v) { return 2 * v + 2; };

void build(int v, int l, int r, bool isExcl) {
   if (l == r) {
      tree[v] = A[l];
      return;
   }
   int mid = (l + r) / 2;
   build(le(v), l, mid, !isExcl);
   build(ri(v), mid + 1, r, !isExcl);

   tree[v] = isExcl ? (tree[le(v)] ^ tree[ri(v)]) : (tree[le(v)] | tree[ri(v)]);
}

void pointUpdate(int v, int l, int r, bool isExcl, int i, int value) {
   if (i > r || i < l) return;
   
   if (l == r) {
      tree[v] = value;
      return;
   }
   int mid = (l + r) / 2;
   pointUpdate(le(v), l, mid, !isExcl, i, value);
   pointUpdate(ri(v), mid + 1, r, !isExcl, i, value);

   tree[v] = isExcl ? (tree[le(v)] ^ tree[ri(v)]) : (tree[le(v)] | tree[ri(v)]);
}

int main() {
   int M; cin >> N >> M;

   bool opRootIsExclusive = N % 2 == 0;
   N = pow(2, N);

   for (int i = 0; i < N; i++) cin >> A[i];

   tree.assign(2 * N, 0);
   build(0, 0, N - 1, opRootIsExclusive);

   int p, b;
   while (M--) {
      cin >> p >> b;
      pointUpdate(0, 0, N-1, opRootIsExclusive, p-1, b);
      cout << tree[0] << endl;
   }

   return 0;
}