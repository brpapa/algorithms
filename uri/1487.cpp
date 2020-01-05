/*
   dynamic programming > knapsack
   problem: six flags
   author: @brnpapa
*/
#include <iostream>
#include <cstring> //memset
using namespace std;

int weight[101], value[101]; //tempo e pontos
int memo[601][101];

//obs: pode colocar o mesmo valor mais de uma vez
int ksTD(int i, int w) {
   //estado: item i, capacidade disponível w

   if (i == -1)
      return 0;

   int &m = memo[w][i];
   if (m != -1) return m;

   if (weight[i] > w) //peso do item já é maior que o limite
      return m = ksTD(i-1, w);

   return m = max(
      ksTD(i-1, w),                     //não adiciona item e o retira
      value[i] + ksTD(i, w - weight[i]) //adiciona item e não o retira
   );
}

int main() {
   int qteAtracoes, tempoMax;

   for (int h = 1; true; h++) {
      scanf("%d %d", &qteAtracoes, &tempoMax);
      if (qteAtracoes == 0)
         break;

      memset(memo, -1, sizeof(memo));
      for (int i = 0; i < qteAtracoes; i++)
         scanf("%d %d", &weight[i], &value[i]);

      printf("Instancia %d\n", h);
      printf("%d\n\n", ksTD(qteAtracoes-1, tempoMax));
   }
   return 0;
}