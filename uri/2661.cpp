/*
   math > number theory > prime numbers > factorization
   difficulty: hard
   date: 14/Sep/2019
   problem: compute the number of divisors of n that can be written as the product of two or more distinct prime numbers (without repetition), 1 <= n <= 10^12
   solution: note that the product of any combination of prime factors of a number will always be a divisor of that number
   by @brnpapa
*/
#include <iostream>
#include <cmath>
#include <set>
#define ll long long
using namespace std;

set<ll> PFs; 

void primeFactors(ll n) {
   int sn = (int)sqrt(n)+1;
   
   for (int i = 2; n > 1 && i <= sn; i++)
      while (n % i == 0)
         n /= i, PFs.insert(i);

   if (n > 1) // o próprio número é primo
      PFs.insert(n);
}

int main() {
   ll n; cin >> n;
   primeFactors(n);

   // qte de todos subconjuntos possíveis - qte de subconjuntos de 1 elem - subconjunto vazio
   cout << pow(2, PFs.size()) - PFs.size() - 1 << endl;
   return 0;
}