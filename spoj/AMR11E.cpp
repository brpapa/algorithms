/*
   math > number theory > prime numbers > sieve of eratosthenes
   difficulty: easy
   date: 14/Nov/2019
   problem: print the n-th number that has at least 3 distinct prime factors
   hint: use modified sieve
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 2700 // max lucky number
using namespace std;

int numDiffPFs[MAX];

void sieve() {
   memset(numDiffPFs, 0, sizeof(numDiffPFs));

   for (int i = 2; i < MAX; i++) {
      if (numDiffPFs[i] == 0)
         for (int j = i; j < MAX; j += i)
            numDiffPFs[j]++; // cada j (múltiplo de i) tem i como um de seus fatores
   }
}

int main() {
   int t, n;
   sieve();

   vector<int> luckyNumbers;
   for (int i = 0; luckyNumbers.size() < 1010; i++)
      if (numDiffPFs[i] >= 3)
         luckyNumbers.push_back(i);

   scanf("%d", &t);
   while (t--) {
      scanf("%d", &n);
      cout << luckyNumbers[n-1] << endl;
   }
   return 0;
}