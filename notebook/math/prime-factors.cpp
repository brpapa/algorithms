/*
   Motivação: gere todos os fatores/divisores primos de n < 9.10^13.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int UB = 1e7; // must be >= sqrt(MAX_N)
vector<int> primes; // all primes in range [2..UB]
bitset<UB+1> is_composite;

/* O(UB*log(log(UB))) */
void build_sieve() {
   primes.clear();
   is_composite.reset(); is_composite[0] = is_composite[1] = 1;

   for (ll i = 2; i <= UB; i++)
      if (!is_composite[i]) {
         primes.push_back(i);

         // descarta todos os múltiplos de i, a partir de i*i
         for (ll j = i*i; j <= UB; j += i)
            is_composite[j] = 1;
      }
}

/* O(sqrt(n)/ln(sqrt(n))) */
vector<int> prime_factors(ll n) {
   vector<int> pfs;

   // para cada primo p em [2..sqrt(n)]
   for (int p : primes) {
      if (p*p > n || n == 1) break;

      while (n % p == 0)
         pfs.push_back(p), n /= p;
   }

   if (n > 1) pfs.push_back(n); // caso especial
   return pfs;
}

int main() {
   build_sieve();
   vector<int> pfs = prime_factors(16);
   for (auto f : pfs) cout << f << " "; cout << endl;
   return 0;
}