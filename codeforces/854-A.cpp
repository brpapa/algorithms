/*
   mathematics > number theory > greatest common divisor (GCD)
   difficulty: easy
   problem: fraction
   date: 26/Dec/2019
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

int main() {
   int N;
   cin >> N;

   int a, b; // numerador, denominador
   b = N / 2 + 1;
   a = N - b;

   while (gcd(a, b) > 1) {
      a--;
      b++;
   }
   cout << a << " " << b << endl;
   return 0;
}