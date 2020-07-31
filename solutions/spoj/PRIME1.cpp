/*
   math > number theory > prime numbers > sieve of eratosthenes
   difficulty: medium
   date: 17/Mar/2020
   problem: print all primes p in [m .. n], 0 <= m <= n <= 10^9, n-m <= 10^5
   hint: sieve + prime checking
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

vector<int> primes;
bitset<35001> is;

void sieve(int ub) {
   is.set(); is[0] = is[1] = false;

   for (int i = 2; i < ub; i++)
      if (is[i]) {
         for (int j = i*i; j < ub; j += i)
            is[j] = false;
         
         primes.push_back(i);
      }
}

bool isPrime(int n) {
   if (n <= primes.back()) return is[(int)n];

   int sn = (int) sqrt(n);

   for (int p : primes) {
      if (p > sn)     break;
      if (n % p == 0) return false;
   }
   return true;
}

int main() {
   sieve(35000); // maior que sqrt(10^9)

   int T; cin >> T;
   while (T--) {
      int m, n; cin >> m >> n;

      for (int i = m; i <= n; i++)
         if (isPrime(i)) cout << i << endl;

      if (T > 0) cout << endl;
   }
   return 0;
}
