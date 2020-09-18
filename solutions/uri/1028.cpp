/*
   math > number theory > greatest common divisor (GCD)
   difficulty: none
   date: none 
   by: @brpapa
*/
#include <iostream>
using namespace std;

//algoritmo de euclides
int gcd(int a, int b) {
   if (a == 0)
      return b;
   return gcd(b%a, a);
}

int main() {
   int n, a, b;
   scanf("%d", &n);
   while (n--) {
      scanf("%d %d", &a, &b);
      printf("%d\n", gcd(a, b));
   }
   return 0;
}