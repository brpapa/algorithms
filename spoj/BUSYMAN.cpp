/*
   greedy
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define inicial second
#define final first
using namespace std;

int main() {
   int t, n, numAtv;
   pair<int, int> tempoAux;
   vector<pair<int, int>> tempo;

   scanf("%d", &t);
   while (t--) {
      scanf("%d", &n);
      tempo.clear();
      for (int i = 0; i < n; i++) {
         scanf("%d %d", &tempoAux.inicial, &tempoAux.final);
         tempo.push_back(tempoAux);
      }
      //ordena por tempo final de forma crescente (compara o .first, no caso .final)
      sort(tempo.begin(), tempo.end());

      int numAtv = 1;
      tempoAux = tempo[0];
      for (int i = 1; i < n; i++)
         if (tempo[i].inicial >= tempoAux.final) {
            numAtv++;
            tempoAux = tempo[i];
         }
      printf("%d\n", numAtv);
   }
   return 0;
}