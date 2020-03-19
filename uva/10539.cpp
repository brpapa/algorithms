/*
   math > number theory > prime numbers > sieve of eratosthenes
   difficulty: medium
   date: 18/Mar/2020
   problem: compute the quantity of non-prime numbers in [lo .. hi] which are divisible by only a single prime number, 0 < lo <= hi < 10^12
   solution: generate all powers of the primes
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <bitset>
#define ll long long
#define UB 1000100 // sqrt(10^12)
using namespace std;

vector<ll> primes;
bitset<UB+1> is; 

void sieve() {
   primes.clear();
   is.set(); is[0] = is[1] = false;

   for (ll i = 2; i <= UB; i++)
      if (is[i]) {
         primes.push_back(i);
         for (ll j = i*i; j <= UB; j += i) is[j] = false;
      }
}

int main() {
   sieve();

   int T; cin >> T;
   while (T--) {
      ll lo, hi; cin >> lo >> hi;
      
      ll ans = 0;

      // para cada primo p em [0 .. sqrt(n)]
      for (ll p : primes) {
         if (p*p > hi) break;

         // para cada potência de p, totalizando O(logp(hi)) iterações
         for (ll j = p*p; j <= hi; j *= p) {
            if (j >= lo) ans++;
         }
      }

      cout << ans << endl;
   }
   return 0;
}
