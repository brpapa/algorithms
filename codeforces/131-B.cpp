/*
   math > combinatorics
   difficulty: easy
   date: 17/Jun/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N; cin >> N;
   map<int, ll> qty;
   for (int i = 0; i < N; i++) {
      int t; cin >> t;
      qty[t] = qty[t] + 1;
   }
   
   ll ans = (qty[0]*(qty[0]-1))/2;
   for (int t = 1; t <= 10; t++)
      ans += qty[t]*qty[-t];

   cout << ans << endl;
   return 0;
}
