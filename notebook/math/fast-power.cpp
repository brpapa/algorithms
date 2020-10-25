/*
   Fast Exponentiation/Power
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

/* O(log(n)) - returns a^n */
ll power(ll a, ll n) {
   if (n == 0)     return 1;
   if (n % 2 == 0) return power(a*a, n/2); // (a^2)^(n/2)
   return a*power(a*a, (n-1)/2);           // a*(a^2)^((n-1)/2)
}

/* O(log(n)) - returns a^n */
ll power_it(ll a, ll n) {
   ll ans = 1;

   while (n > 0) {
      if (n & 1ll) ans *= a; // if n is odd (only on first (possibly) and last iteration)

      n >>= 1ll; // n /= 2
      a *= a;
   }

   return ans;
}

/* O(log(n)) - returns (a^n) % MOD */
ll power_mod(ll a, ll n) {
   if (n == 0)     return 1;
   if (n % 2 == 0) return power_mod((a*a)%MOD, n/2) % MOD;
   return (a * power_mod((a*a)%MOD, (n-1)/2)) % MOD;
}

/* e.g. */
int main() {
   cout << power(2,5) << endl;
   return 0;
}