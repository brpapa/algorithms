/*
   mathematics | basic
   problem: prime or not prime!
*/
#include <iostream>
#include <math.h>
using namespace std;

bool ehPrimo(int n) {
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
      printf("%s\n", ehPrimo(tmp) ? "YES" : "NO");
   }
   return 0;
}