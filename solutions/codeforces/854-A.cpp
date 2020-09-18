/*
   math > number theory > greatest common divisor (GCD)
   difficulty: easy
   date: 26/Dec/2019
   problem: given n, determine maximum possible proper (a < b) and irreducible fraction a/b such that a+b == n
   by: @brpapa
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

int main() {
   int n; cin >> n;

   int a, b; // numerador, denominador
   b = n / 2 + 1;
   a = n - b;

   while (gcd(a, b) > 1) a--, b++;

   cout << a << " " << b << endl;
   return 0;
}