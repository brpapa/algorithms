/*
   dynamic programming
   difficulty: easy
   problem: flight planner
   date: 29/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#define min3(a, b, c) ((a) < (b)? min(a, c) : min(b, c))
#define INF (int)0x7f7f7f7f
using namespace std;

int N; // voar da posição (0, 0) até (0, N)
int windStrengths[10][1010]; // vento em (h, n)

int memo[10][1010];
int dp(int h, int n) {
   // posiçao atual n, altura h

   if (h < 0 || h > 9) return INF; // inválido
   if (n == N) return (h == 0)? 0: INF;

   int &ans = memo[h][n];
   if (ans != -1) return ans;

   return ans = 0 - windStrengths[h][n] + min3(
      60 + dp(h+1, n+1), // climb
      30 + dp(h, n+1),   // hold
      20 + dp(h-1, n+1)  // sink
   );
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T; cin >> T;
   while (T--) {
      cin >> N; N /= 100;

      for (int h = 9; h >= 0; h--)
         for (int n = 0; n < N; n++) 
            cin >> windStrengths[h][n];
   
      memset(memo, -1, sizeof memo);
      cout << dp(0, 0) << endl << endl;
   }
   return 0;
}
