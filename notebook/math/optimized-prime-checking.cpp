/*
   Motivation: check if a number n is prime.
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
bool is_prime(ll n) {
	if (n <= primes.back()) return !is_composite[(int)n];

   // para cada primo em [2..sqrt(n)]
	for (int i = 0; primes[i]*primes[i] <= n; i++)
		if (n % primes[i] == 0)
         return false;

	return true;
}

int main() {
   build_sieve();
   cout << is_prime(547) << endl;
   return 0;
}