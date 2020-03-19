// TODO: k, entender o que foi feito (com halim)
/*
   dynamic programming > minimax
   difficulty: none
   date: none
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
#define ALBERTO 0
#define WANDERLEY 1
#define ll long long
using namespace std;

ll memo[10000][10000];
int seq[10000];

// retorna a pontuação que o jogador da vez pode obter de seq[e] até seq[d]
ll dp(int e, int d, int player) {
   if (d < e) return 0;

   ll &ans = memo[d][e];
   if (ans != -1) return ans;

   if (player == ALBERTO)
      return ans = max(
         (ll)seq[e] + dp(e + 1, d, WANDERLEY), // ALBERTO remove esq
         (ll)seq[d] + dp(e, d - 1, WANDERLEY)  // ALBERTO remode dir
      );
   
   return ans = min(
      dp(e + 1, d, ALBERTO), // WAND remove esq
      dp(e, d - 1, ALBERTO)  // WAND remode dir
   );
}

int main() {
   int n;
   while (scanf("%d", &n) != EOF) {
      for (int i = 0; i < n; i++) {
         scanf("%d", &seq[i]);
         for (int j = 0; j <= i; j++) memo[i][j] = -1;
      }
      printf("%lld\n", dp(0, n-1, ALBERTO));
   }
   return 0;
}