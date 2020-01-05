/*
   mathematics > number theory > prime numbers > sieve of eratosthenes
   difficulty: medium
   problem: vasya and petya's game
   date: 26/Dec/2019
   author: @brnpapa
*/
#include <bitset>
#include <iostream>
#include <vector>
#define MAX_N 1010
using namespace std;

int main() {
   bitset<MAX_N> isPrime;
   isPrime.set();
   for (int i = 2; i < MAX_N; i++) {
      if (isPrime[i]) {
         for (int j = i * i; j < MAX_N; j += i)
            isPrime[j] = 0;
      }
   }

   int N;
   cin >> N;

   vector<int> ans;
   for (int i = 2; i <= N; i++)
      if (isPrime[i])
         for (int j = i; j <= N; j *= i) {
            // o primo e seus quadrados, cubos, etc
            ans.push_back(j);
         }

   cout << ans.size() << endl;
   for (int a : ans)
      cout << a << " ";
   return 0;
}