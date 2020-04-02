/*
   math > game theory > minimax
   difficulty: medium
   date: 28/Mar/2020
   problem: alberto and wanderley take one of two cards at the edges of the cards sequence, alberto want maximize it
   solution: fill memo table in row-major order
   by @brnpapa
*/
#include <iostream>
#define ll long long
#define ALB 0
#define WAN 1
using namespace std;

int A[10010];

ll memo[10010][10010];
ll dp(bool p, int l, int r) {
   // cartas atuais A[l:r], jogador atual p

   if (l > r) return 0ll;

   ll &ans = memo[r][l]; // r >= l
   if (ans != -1) return ans;

   if (p == ALB) {
      return ans = max(
         (ll)A[l] + dp(!p, l+1, r),
         (ll)A[r] + dp(!p, l, r-1)
      );
   }
   else {
      // WAN escolhe estado em que ALB recebe menos
      return ans = min(
         dp(!p, l+1, r),
         dp(!p, l, r-1)
      );
   }
}

int main() {
   int N;
   while (cin >> N) {
      for (int i = 0; i < N; i++) {
         cin >> A[i];
         for (int j = 0; j <= i; j++) memo[i][j] = -1;
      }
      cout << dp(ALB, 0, N-1) << endl;
   }
   return 0;
}
