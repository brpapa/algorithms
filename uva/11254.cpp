/*
   math > ad-hoc > arithmetic progression
   difficulty: medium
   date: 14/Feb/2020 
   by @brnpapa
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   while (true) {
      double sn; cin >> sn; if (sn == -1) break;
      printf("%.lf = ", sn);

      // força bruta no tamanho (n) da P.A. de d=1
      // o maior n possível é quando a1=1, logo sn = (1+n)*n/2
      for (int n = (int)sqrt(2*sn); n >= 1; n--) {
         double a1 = (2.0*sn - n*n + n)/(2.0*n);

         if (a1 == (double)(int)a1) {
            printf("%.lf + ... + %.lf\n", a1, a1+n-1); // a1, an 
            break;
         }
      }
   }   
   return 0;
}
