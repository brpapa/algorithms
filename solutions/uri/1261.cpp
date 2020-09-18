/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   int M, N; cin >> M >> N;

   map<string, ll> dict;
   while (M--) {
      string s; ll n; cin >> s >> n;
      dict[s] = n;
   }

   while (N--) {
      ll ans = 0;
      string s;
      while (cin >> s && s != ".") {
         ans += dict[s];
      }
      cout << ans << endl;
   }
   return 0;
}
