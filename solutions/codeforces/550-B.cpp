/*
   brute force > iterative > all subsets
   difficulty: easy
   date: 24/Oct/2020
   hint: use bitmask
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1 << 30;

int main() {
   int N; ll l, r, x; cin >> N >> l >> r >> x;
   vector<ll> difficulties(N); for (ll &d : difficulties) cin >> d;

   ll ans = 0;
   for (int mask = 0; mask < (1 << N); mask++) {
      ll qty = 0;
      ll total = 0;
      ll min_d = INF;
      ll max_d = -INF;

      for (int i = 0; i < N; i++)
         if (mask & (1 << i)) {
            total += difficulties[i];
            min_d = min(min_d, difficulties[i]);
            max_d = max(max_d, difficulties[i]);
            qty++;
         }

      if (qty >= 2 && l <= total && total <= r && (max_d-min_d) >= x)
         ans++;
   }

   cout << ans << endl;
	return 0;
}
