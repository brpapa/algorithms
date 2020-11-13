/*
   Motivation: generate all primes until an upper bound UB < 10^7.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int UB = 1e7;
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

int main() {
   build_sieve();
}
