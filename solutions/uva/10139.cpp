/*
   math > number theory > prime numbers > prime factorization
   difficulty: medium
   date: 21/Mar/2020
   problem: do n! is divisible by m?
   hint: check if the prime factors of m are contained in the prime factors of n!
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#define UB 35000 // sqrt(10^9)
#define ll long long
using namespace std;

vector<int> primes;
void sieve() {
   primes.clear();
   bitset<UB+1> is; is.set(); is[0] = is[1] = 0;

   for (int i = 2; i <= UB; i++)
      if (is[i]) {
         primes.push_back(i);
         for (int j = i*i; j <= UB; j += i) is[j] = 0;
      }
}

int getPowers(int n, int p) {
   int count = 0;
   for (ll power = p; n >= power; power *= p)
      count += n/power;
   return count;
}

int main() {
   sieve();
   int N, M;
   while (cin >> N >> M) {
      bool divide = 1;

      // fatora M
      int m = M; 
      for (int p: primes) {
         if (p*p > m || m == 1 || !divide) break;

         int pFreq = 0;
         while (m % p == 0) pFreq++, m /= p;

         if (pFreq > getPowers(N, p)) divide = 0;
      }
      if (m > 1 && 1 > getPowers(N, m)) divide = 0;

      printf("%d %s %d!\n", M, divide? "divides": "does not divide", N);
   }
   return 0;
}
