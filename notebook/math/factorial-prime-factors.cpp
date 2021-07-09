/*
   Motivation: get all prime factors of n!

   ---
   10! = 2.3.4.5.6.7.8.9.10
   Note que um número p qualquer aparece ⌊10/p⌋ vezes nos fatores de 10!

   10! = 2.3.4.5.6.7.8.9.10
         2   2   2   2    2 = 2 aparece 5 vezes
             2       2      = 4 aparece 2 vezes
                     2      = 8 aparece 1 vez

   10! = (2^8).(3^4).(5^2).7
   multiplicy(10,2) = 10/2 + 10/4 + 10/8 + 10/16 = 5+2+1+0
   multiplicy(10,3) = 10/3 + 10/9 + 10/27        = 3+1+0
   multiplicy(10,5) = 10/5 + 10/25               = 2+0
   multiplicy(10,7) = 10/7 + 10/49               = 1+0
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

/* O(log(n)) - retorna a multiplicidade de p entre os fatores primos de n! */
int multiplicy(int n, int p) {
   int count = 0;
   for (ll q = p; n >= q; q *= p) count += n/q;
   return count;
}

map<int, int> prime_factors_of_factorial(int n) {
   map<int, int> pfs; // primo, multiplicidade
   for (int p : primes)
      if (p <= n)
         pfs[p] = multiplicy(n, p);
   return pfs;
}

int main() {
   build_sieve();
   map<int, int> pfs = prime_factors_of_factorial(10);
   for (auto pf : pfs) cout << pf.first << " " << pf.second << endl;
   return 0;
}