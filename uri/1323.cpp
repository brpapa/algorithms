/*
   math > number theory
   problem: feynman
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int rec(int n) {
   if (n == 1)
      return 1;
   return n * n + rec(n - 1);
}

int main() {
   int n;
   cin >> n;
   do {
      printf("%d\n", rec(n));
      cin >> n;
   } while (n != 0);
   return 0;
}