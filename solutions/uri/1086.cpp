/*
   greedy
   difficulty: none
   date: none 
   by: @brpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//retorna o menor número possível de tabuas ou -1 se for impossivel
int menorNumTabuas(vector<int> comp, float qteFilasTotal, int compFilas) {
   if (qteFilasTotal / (int)qteFilasTotal != 1) //número de filas não exato
      return -1;

   int qteTabuas = 0, qteFilas = 0;
   int j = comp.size() - 1; //pos do ultimo comprimento

   //procura a partir do maior comprimento
   for (int i = 0; i < comp.size(); i++) {
      if (comp[i] == compFilas) {
         qteFilas++;
         qteTabuas++;
      } else if (comp[i] < compFilas) {
         //procura a partir do menor comprimento
         while (j > i) {
            if (comp[i] + comp[j] == compFilas) {
               qteFilas++;
               qteTabuas += 2;
               j--; //tábua já usada
               break;
            } else if (comp[i] + comp[j] > compFilas)
               break;
            j--; //comp[i]+comp[j] tem comprimento insuficiente
         }
      }
      if (qteFilas == qteFilasTotal)
         return qteTabuas;
   }
   return -1;
}

int main() {
   int n, m, l, k, aux;
   while (true) {
      scanf("%d %d", &m, &n); //dimensões do salão em metros
      if (m == 0 && n == 0)
         return 0;
      scanf("%d", &l); //largura das tábuas em cm
      scanf("%d", &k); //número de tábuas
      vector<int> comp;
      for (int i = 0; i < k; i++) {
         scanf("%d", &aux);
         comp.push_back(aux); //comprimento da tábua i em metros
      }
      //ordena de forma decrescente
      sort(comp.begin(), comp.end(), greater<int>());

      int qteTabuasVerticais = menorNumTabuas(comp, m / (l / 100.0), n);
      int qteTabuasHorizontais = menorNumTabuas(comp, n / (l / 100.0), m);

      if (qteTabuasVerticais == -1 && qteTabuasHorizontais == -1)
         printf("impossivel\n");
      else if (qteTabuasVerticais == -1)
         printf("%d\n", qteTabuasHorizontais);
      else if (qteTabuasHorizontais == -1)
         printf("%d\n", qteTabuasVerticais);
      else
         printf("%d\n", (qteTabuasHorizontais < qteTabuasVerticais) ? qteTabuasHorizontais : qteTabuasVerticais);
   }
}