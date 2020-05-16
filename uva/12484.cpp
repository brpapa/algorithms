/*
   math > game theory > minimax
   difficulty: medium
   date: 28/Mar/2020
   problem: alberto and wanderley take one of two cards at the edges of the cards sequence, alberto want maximize it
   hint: fill memo table in row-major order
   by: @brnpapa
*/
#include <iostream>
using namespace std;

typedef long long ll;
const int pALB = 0;
const int pWAN = 1;

int A[10010];

ll memo[10010][10010];
ll minimax(bool p, int l, int r) {
   // cartas atuais A[l:r], jogador atual p

   if (l > r) return 0ll;

   ll &ans = memo[r][l]; // r >= l
   if (ans != -1) return ans;

   if (p == pALB) {
      return ans = max(
         (ll)A[l] + minimax(!p, l+1, r),
         (ll)A[r] + minimax(!p, l, r-1)
      );
   }
   else {
      // pWAN escolhe estado em que pALB recebe menos
      return ans = min(
         minimax(!p, l+1, r),
         minimax(!p, l, r-1)
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
      cout << minimax(pALB, 0, N-1) << endl;
   }
   return 0;
}
