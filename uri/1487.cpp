/*
   dynamic programming | knapsack 
   problem: six flags
*/
#include <iostream>
#include <cstring> //memset
using namespace std;

int weight[101], value[101]; //tempo e pontos
int memo[601][101];

//obs: pode colocar o mesmo valor mais de uma vez
int knapsack(int w, int n) {
   if (memo[w][n] != -1)
      return memo[w][n];
   
   if (w == 0 || n == 0) //capacidade ou qte de itens nula
      return memo[w][n] = 0;

   if (weight[n-1] > w) //peso do item já é maior que o limite
      return memo[w][n] = knapsack(w, n-1);

   return memo[w][n] = max(
      knapsack(w, n-1),                         //não adiciona item e o retira
      value[n-1] + knapsack(w - weight[n-1], n) //adiciona item e não o retira
   );
}

int main() {
   int qteAtracoes, tempoMax;

   for (int h = 1; true; h++)
   {
      scanf("%d %d", &qteAtracoes, &tempoMax);
      if (qteAtracoes == 0)
         break;

      memset(memo, -1, sizeof(memo));
      for (int i = 0; i < qteAtracoes; i++)
         scanf("%d %d", &weight[i], &value[i]);

      printf("Instancia %d\n", h);
      printf("%d\n\n", knapsack(tempoMax, qteAtracoes));
   }
   return 0;
}