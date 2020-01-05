/*
   mathematics > number theory > all divisors
   problem: divine numbers
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std;

long long somaTodosDiv[MAX];

//semelhante ao crivo de erastótenes, mas sem fatores primos
void preprocess() {
   memset(somaTodosDiv, 0, sizeof(somaTodosDiv));

   for (int i = 1; i < MAX; i++) {
      for (int j = i; j < MAX; j += i) //para cada j múltiplo de i
         somaTodosDiv[j] += i; //pois todos j são também divisores de i

      somaTodosDiv[i] += somaTodosDiv[i-1]; //número divino
   }
}

int main() {
   int n;
   preprocess();

   while(true) {
      scanf("%d", &n);
      if (n == 0)
         break;
      printf("%lld\n", somaTodosDiv[n]);
   }
   return 0;
}