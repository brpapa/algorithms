/*
   dynamic programming > max 2D range sum
   difficulty: easy
   problem: maximum sum
   date: 17/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#define INF (int)0x3f3f3f3f
using namespace std;

int sumAcc[110][110];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int N; cin >> N;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
         cin >> sumAcc[i][j];
         sumAcc[i][j] = sumAcc[i][j]
          + ((i > 0)? sumAcc[i-1][j] : 0)
          + ((j > 0)? sumAcc[i][j-1] : 0)
          - ((i > 0 && j > 0)? sumAcc[i-1][j-1] : 0);
      }
   
   int ans = -INF;
   for (int l = 0; l < N; l++) for (int c = 0; c < N; c++)
      for (int i = l; i < N; i++) for (int j = c; j < N; j++)
         ans = max(ans, sumAcc[i][j]
            - ((l > 0)? sumAcc[l-1][j] : 0)
            - ((c > 0)? sumAcc[i][c-1] : 0)
            + ((l > 0 && c > 0)? sumAcc[l-1][c-1] : 0)
         );
   cout << ans << endl;
   return 0;
}
