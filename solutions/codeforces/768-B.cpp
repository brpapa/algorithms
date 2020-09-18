/*
   divide & conquer
   difficulty: medium
   date: 16/Apr/2020
   hint: knowing the size of the final array with a little math, use the same idea to query a range in a segment tree
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qty1(ll v) {
   if (v <= 1) return v;
   return v%2 + 2*qty1(v/2);
}

ll ql, qr;
int rangeQuery(ll v, ll l, ll r) {
   if (l > qr || r < ql)   return 0;
   if (l >= ql && r <= qr) return qty1(v);

   ll m = (l+r)/2;
   ll k = (m >= ql && m <= qr)? v%2: 0;
   return rangeQuery(v/2, l, m-1) + k + rangeQuery(v/2, m+1, r);
}

int main() {
   ll V; cin >> V >> ql >> qr; ql--; qr--;

   ll N = 1; // calcula o tamanho do array final em O(log2(V))
   for (ll i = 1, p = 0; i <= V; i *= 2) 
      N = p+i, p = N; 
   
   cout << rangeQuery(V, 0, N-1) << endl;
   return 0;
}
