/*
   mathematics > number theory > prime numbers > factorization
   problem: despojados
   author: @brnpapa
*/
#include <iostream>
#include <cmath>
#include <set>
#define lli long long int
using namespace std;

set<lli> factors; 

void toFactor(lli n) {
   int lim = sqrt(n)+1;
   
   for (int i = 2; n > 1 && i <= lim; i++)
      while (n % i == 0) {
         n /= i;
         factors.insert(i);
      }

   if (n > 1) //o próprio número é primo
      factors.insert(n);
}

int main() {
   lli n, qtyComb;

   cin >> n;
   toFactor(n);

   //qte de todos subconjuntos possíveis - qte de subconjuntos de 1 elem - subconjunto vazio
   qtyComb = pow(2, factors.size()) - factors.size() - 1;
   cout << qtyComb << endl;
   return 0;
}