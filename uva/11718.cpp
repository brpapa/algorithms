/*
   math > ad-hoc > finding pattern
   difficulty: hard
   problem: fantasy of a summation
   date: 16/Feb/2020
   solution: compute K * N^(K-1) * sumA using fast power mod
   author: @brnpapa
*/
#include <iostream>
#define ll long long
using namespace std;

ll fastPowerMod(ll a, ll n, int mod) {
   if (n == 0) return 1;
   if (n == 1) return a % mod;
   if (n % 2 == 0) return fastPowerMod((a * a) % mod, n / 2, mod);
   return ((a % mod) * fastPowerMod((a * a) % mod, (n - 1) / 2, mod)) % mod;
}

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      ll N, K, MOD; cin >> N >> K >> MOD;
      
      ll sumA = 0, a;
      for (int n = 0; n < N; n++) cin >> a, sumA += a;

      ll ans = (K * fastPowerMod(N, K-1, MOD)) % MOD;
      ans = (ans * sumA) % MOD;
      printf("Case %d: %lld\n", t, ans);
   }
   return 0;
}
