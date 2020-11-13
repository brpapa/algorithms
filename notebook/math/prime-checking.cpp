/*
   Motivation: check if a number n is prime.

   Checar se n é divisível por algum d em [2..n-1] equivale à checar se n é divisível por algum d em [2..sqrt(n)], pois se não há nenhum d < sqrt(n), não haverá d > sqrt(n), por conta da propriedade dos pares multiplicativos do conjunto de divisores de um número.
*/
#include <bits/stdc++.h>
using namespace std;

/* O(sqrt(n)) */
bool is_prime(int n) {
   if (n <= 1) return false;

   for (int d = 2; d*d <= n; d++)
      if (n % d == 0)
         return false;
   return true;
}

int main() {
   cout << is_prime(1) << endl;
   cout << is_prime(2) << endl;
   cout << is_prime(3) << endl;
   cout << is_prime(4) << endl;
}