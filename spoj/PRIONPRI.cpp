/*
   math > number theory > prime numbers
   difficulty: none
   problem: prime or not prime!
   date: none
   author: @brnpapa
*/
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
   for (int i = 2; i <= sqrt(n); i++)
      if (n % i == 0)
         return false;
   return true;
}

int main() {
   int t, tmp;
   cin >> t;
   for (int i = 0; i < t; i++) {
      cin >> tmp;
      printf("%s\n", isPrime(tmp) ? "YES" : "NO");
   }
   return 0;
}