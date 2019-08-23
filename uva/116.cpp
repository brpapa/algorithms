/*
   dynamic programming | minimum sum
   problem: unidirectional TSP
   author: @brnpapa
*/
#include <iostream>
#include <queue>
#include <cstring>
#define INF 2147483647
#define min(a, b) ((a)<(b) ? (a):(b))
#define min3(a, b, c) ((a)<(b) ? min(a, c):min(b, c))
//reescreve n, caso tenha extrapolado os limites 0 e sup-1
#define adj(n, sup) ((n)<(0)? (sup-1):((n)%(sup)))
#define maxLIN 10
#define maxCOL 100
using namespace std;

int m[maxLIN][maxCOL], memo[maxLIN][maxCOL];
int ans[maxCOL]; //ans[i] = linha do melhor caminho na coluna i
int qteLIN, qteCOL;

//implementação bottom-up, pois com top-down precisaria chamar a função para todas 
//as linhas da coluna 0 para que memo seja preenchido completamente, antes de preencher ans
void dp(int qteLIN, int qteCOL) {
   //caso base
   for (int i = 0; i < qteLIN; i++)
      memo[i][qteCOL-1] = m[i][qteCOL-1];

   //preenche memo, da última para a primeira coluna
   for (int j = qteCOL-2; j >= 0; j--)
      for (int i = 0; i < qteLIN; i++)
         memo[i][j] = m[i][j] + min3(
            memo[adj(i-1, qteLIN)][j+1],
            memo[i][j+1],
            memo[adj(i+1, qteLIN)][j+1]
         );
}

void recover() {
   int minAux = INF;

   //coluna 0
   for (int i = 0; i < qteLIN; i++)
      if (memo[i][0] < minAux) {
         minAux = memo[i][0];
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
         
         if (memo[i][j] <= minAux) { //para minAux iguais prioriza o menor i
            minAux = memo[i][j];
            ans[j] = i;
         }
      }
   }
}

int main() {
   while (scanf("%d %d", &qteLIN, &qteCOL) != EOF) {
      memset(memo, -1, sizeof(memo));
      for (int i = 0; i < qteLIN; i++)
         for (int j = 0; j < qteCOL; j++)
            scanf("%d", &m[i][j]);

      dp(qteLIN, qteCOL);
      recover(); //gera ans

      for (int j = 0; j < qteCOL-1; j++)
         printf("%d ", ans[j]+1);
      printf("%d\n%d\n", ans[qteCOL-1]+1, memo[ans[0]][0]);
   }
   return 0;
}