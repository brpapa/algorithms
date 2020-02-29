/*
   dynamic programming > minimax
   difficulty: none
   problem: cards
   date: none
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#define ALBERTO 0
#define WANDERLEY 1
#define lli long long int
using namespace std;

lli memo[10000][10000];
int seq[10000];

//retorna a pontuação que o jogador da vez pode obter de seq[e] até seq[d]
lli dpTD(int e, int d, int jogador) {
   if (d - e < 0)
      return 0;

   lli &m = memo[d][e];
   if (m != -1) return m;

   if (jogador == ALBERTO)
      return m = max(
         (lli)seq[e] + dpTD(e + 1, d, WANDERLEY), //ALBERTO remove esq
         (lli)seq[d] + dpTD(e, d - 1, WANDERLEY)  //ALBERTO remode dir
      );
   
   return m = min(
      dpTD(e + 1, d, ALBERTO), //WAND remove esq
      dpTD(e, d - 1, ALBERTO)  //WAND remode dir
   );
}

int main() {
   int n;
   while (scanf("%d", &n) != EOF) {
      for (int i = 0; i < n; i++) {
         scanf("%d", &seq[i]);
         for (int j = 0; j <= i; j++)
            memo[i][j] = -1;
      }
      printf("%lld\n", dpTD(0, n - 1, ALBERTO));
   }
   return 0;
}