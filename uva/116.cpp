/*
   dynamic programming > traveling salesman problem (TSP)
   difficulty: medium
   problem: unidirectional tsp
   date: 14/Nov/2019
   author: @brnpapa
*/
#include <iostream>
#include <queue>
#include <cstring>
#define INF 2147483647
#define min(a, b) ((a)<(b) ? (a):(b))
#define min3(a, b, c) ((a)<(b) ? min(a, c):min(b, c))
#define adj(n, sup) ((n)<(0)? (sup-1):((n)%(sup))) //reescreve n, caso tenha extrapolado os limites 0 e sup-1
using namespace std;

int m[10][100], tab[10][100];
int ans[100]; //ans[i] = linha do melhor caminho na coluna i
int qteLIN, qteCOL;

void dpBU(int qteLIN, int qteCOL) {
   //caso base
   for (int i = 0; i < qteLIN; i++)
      tab[i][qteCOL-1] = m[i][qteCOL-1];

   //preenche tab, da última para a primeira coluna, de cima para baixo
   for (int j = qteCOL-2; j >= 0; j--)
      for (int i = 0; i < qteLIN; i++)
         tab[i][j] = m[i][j] + min3(
            tab[adj(i-1, qteLIN)][j+1],
            tab[i][j+1],
            tab[adj(i+1, qteLIN)][j+1]
         );
}

//! seria mais simples rodar dp de novo
void recover() {
   int minAux = INF;

   //coluna 0
   for (int i = 0; i < qteLIN; i++)
      if (tab[i][0] < minAux) {
         minAux = tab[i][0];
         ans[0] = i;
      }
   //próximas colunas
   for (int j = 1; j < qteCOL; j++) {
      minAux = INF;

      priority_queue<int> path; //guarda linhas válidas
      for (int k = -1; k <= 1; k++)
         path.push(adj(ans[j-1]+k, qteLIN));

      while (!path.empty()) {  
         int i = path.top(); 
         path.pop();
         
         if (tab[i][j] <= minAux) { //para minAux iguais prioriza o menor i
            minAux = tab[i][j];
            ans[j] = i;
         }
      }
   }
}

int main() {
   while (scanf("%d %d", &qteLIN, &qteCOL) != EOF) {
      for (int i = 0; i < qteLIN; i++)
         for (int j = 0; j < qteCOL; j++)
            scanf("%d", &m[i][j]);

      dpBU(qteLIN, qteCOL);
      recover(); //gera ans

      for (int j = 0; j < qteCOL-1; j++)
         printf("%d ", ans[j]+1);
      printf("%d\n%d\n", ans[qteCOL-1]+1, tab[ans[0]][0]);
   }
   return 0;
}