/*
   data structures > queue
   problem: supermarket line
   author: @brnpapa
*/
#include <iostream>
#include <queue>
using namespace std;

typedef struct reg {
   int id, tempoPorItem, tempoTotal;
} funcionario;

//retorna o id do próximo funcionário disponível para atender
int min(funcionario caixa[], int n) {
   funcionario min = caixa[0];
   for (int i = 1; i < n; i++)
      if (caixa[i].tempoTotal < min.tempoTotal)
         min = caixa[i];
   return min.id;
}
int main() {
   int aux, n, m;
   scanf("%d %d", &n, &m);
   funcionario caixa[10000];
   for (int i = 0; i < n; i++) {
      scanf("%d", &caixa[i].tempoPorItem);
      caixa[i].tempoTotal = 0;
      caixa[i].id = i;
   }
   queue<int> qteItens;
   for (int i = 0; i < m; i++) {
      scanf("%d", &aux);
      qteItens.push(aux);
   }

   while (!qteItens.empty()) {
      int id = min(caixa, n);
      caixa[id].tempoTotal += caixa[id].tempoPorItem * qteItens.front();
      qteItens.pop();
   }
   int max = caixa[0].tempoTotal;
   for (int i = 1; i < n; i++)
      if (caixa[i].tempoTotal > max)
         max = caixa[i].tempoTotal;
   printf("%d\n", max);
   return 0;
}