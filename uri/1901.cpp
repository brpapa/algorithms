/*
   ad-hoc > data structures > set
   problem: butterflies
   author: @brnpapa
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
   int n, mapa[200][200], l, c;
   set<int> borboletas;

   scanf("%d", &n);
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         scanf("%d", &mapa[i][j]);

   for (int i = 0; i < n*2; i++) {
      scanf("%d %d", &l, &c);
      borboletas.insert(mapa[--l][--c]);
   }
   printf("%d\n", borboletas.size());
   return 0;
}