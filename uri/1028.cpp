/*
   mathematics | common maximum divisor
   problem: collectable cards
*/
#include <iostream>
using namespace std;

//algoritmo de euclides
int mdc(int a, int b) {
   if (a == 0)
      return b;
   return mdc(b%a, a);
}

int main() {
   int n, a, b;
   scanf("%d", &n);
   while (n--) {
      scanf("%d %d", &a, &b);
      printf("%d\n", mdc(a, b));
   }
   return 0;
}