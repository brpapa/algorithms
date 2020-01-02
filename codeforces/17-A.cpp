/*
   mathematics | number theory | prime numbers | sieve of eratosthenes
   problem: noldbach problem
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

bool isPrime[MAX];
bool isSum[MAX];

void sieve() {
   memset(isPrime, true, sizeof(isPrime));
   isPrime[0] = isPrime[1] = false;

   for (int i = 2; i*i < MAX; i++)
      if (isPrime[i])
         for (int j = i * i; j < MAX; j += i)
            isPrime[j] = false;
}

void checkSum() {
   memset(isSum, false, sizeof(isSum));

   int last = 2;
   for (int i = 3; 1+i+last < MAX; i++)
      if (isPrime[i]) {
         //1+i+last: é a soma de 1 com os dois últimos primos
         isSum[1+i+last] = true;
         last = i;
      }
}

int main() {
   int qty[MAX], n, k;

   sieve();
   checkSum();
   memset(qty, 0, sizeof(qty));

   for (int i = 2; i < MAX; i++)
      if (isPrime[i] && isSum[i])
         for (int j = i; j < MAX; j++)
            qty[j]++;

   cin >> n >> k;
   cout << (qty[n]>=k? "YES":"NO") << endl;

   return 0;
}