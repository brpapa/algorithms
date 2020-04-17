/*
   math > number theory
   difficulty: medium
   date: 28/May/2019
   problem: print n-th divine number, the one that is equal to the sum of the sum of each divisor from 1 to n
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;

long long somaTodosDiv[MAX];

int main() {
   memset(somaTodosDiv, 0, sizeof(somaTodosDiv));

   for (int i = 1; i < MAX; i++) {
      for (int j = i; j < MAX; j += i) // para cada j múltiplo de i
         somaTodosDiv[j] += i;

      somaTodosDiv[i] += somaTodosDiv[i-1]; // número divino
   }

   int n;
   while (cin >> n && n) printf("%lld\n", somaTodosDiv[n]);
   return 0;
}