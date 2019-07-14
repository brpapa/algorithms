/*
   number theory | prime numbers | sieve of eratosthenes
   problem: distinct primes
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#define MAX 2700 //max lucky number
using namespace std;

int factors[MAX]; //quantidade de fatores primos distintos de i

//crivo de erastótenes adaptado
void sieve() {
   memset(factors, 0, sizeof(factors));

   for (int i = 2; i < MAX; i++) {
      if (factors[i] == 0) 
         for (int j = i; j < MAX; j += i)
            factors[j]++; //cada j (múltiplo de i) tem i como um de seus fatores
   }
}

int main() {
   int t, n;
   sieve();

   int luckyNumbers[1000], j = 0;
   for (int i = 0; j < 1000; i++)
      if (factors[i] >= 3)
         luckyNumbers[j++] = i;

   scanf("%d", &t);
   while (t--) {
      scanf("%d", &n);
      cout << luckyNumbers[n-1] << endl;
   }
   return 0;
}