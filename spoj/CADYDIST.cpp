/*
   greedy
   difficulty: easy
   date: 21/Feb/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
   while (1) {
      int N; cin >> N; if (!N) break;
      vector<ll> c(N), p(N);
      for (ll &v : c) cin >> v;
      for (ll &v : p) cin >> v;

      sort(c.begin(), c.end());
      sort(p.begin(), p.end(), greater<ll>());

      ll ans = 0;
      for (int n = 0; n < N; n++) ans += c[n]*p[n];
      cout << ans << endl;
   }
   return 0;
}