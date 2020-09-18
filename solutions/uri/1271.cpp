/*
   ad-hoc
   difficulty: none
   date: none 
   by: @brpapa
*/
#include <iostream>
using namespace std;

int main() {
   int genome[50005], ans[50005];
   int n, r, i, j, q, k, idx = 1;

   while (true) {
      scanf("%d", &n);
      if (n == 0) return 0;

      for (int i = 1; i <= n; i++)
         genome[i] = ans[i] = i;

      scanf("%d", &r); //qte de inversoes
      while (r--) {
         scanf("%d %d", &i, &j);

         for (int k = 0; k < (j-i+1)/2; k++) {
            swap(genome[i+k], genome[j-k]);

            //atualiza vetor invertido
            ans[genome[i+k]] = i+k;
            ans[genome[j-k]] = j-k;
         }
      }

      printf("Genome %d\n", idx++);
      scanf("%d", &q); //qte de consultas
      while (q--) {
         scanf("%d", &k);
         printf("%d\n", ans[k]);
      }
   }
}