/*
   ad-hoc
   problem: assigning teams
*/
#include <iostream>
using namespace std;

int main() {
   int a, b, c, d, min, aux;
   scanf("%d %d %d %d", &a, &b, &c, &d);
   min = abs((a + b) - (c + d));

   aux = abs((a + c) - (b + d));
   if (aux < min)
      min = aux;

   aux = abs((a + d) - (b + c));
   if (aux < min)
      min = aux;

   printf("%d\n", min);
   return 0;
}