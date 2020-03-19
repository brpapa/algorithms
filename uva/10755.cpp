/*
   dynamic programming > max 2D range sum
   difficulty: hard
   date: 18/Jan/2020
   problem: max 3D range sum
   solution: use max 2D range sum in two of the three dimensions and max 1D range sum (kadane) on the third dimension
   by @brnpapa
*/
#include <iostream>
#define ll long long
#define INF (ll)0x3f3f3f3f3f3f3f3f
using namespace std;

ll cube[22][22][22];
ll accSum[22][22][22]; // accSum[a][i][j]: soma acumulada da a-ésima sub-matriz 2D [(0,0) .. (i,j)]

// soma da a-ésima sub-matriz 2D [(l, c) .. (i, j)] em O(1)
ll rsq(int a, int l, int c, int i, int j) {
   return accSum[a][i][j]
      - (l > 0 ? accSum[a][l-1][j] : 0)
      - (c > 0 ? accSum[a][i][c-1] : 0)
      + (l > 0 && c > 0 ? accSum[a][l-1][c-1] : 0);
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T; cin >> T;
   while (T--) {
      int A, B, C; cin >> A >> B >> C;
      for (int a = 0; a < A; a++)
         for (int b = 0; b < B; b++)
            for (int c = 0; c < C; c++) {
               cin >> cube[a][b][c];
               accSum[a][b][c] = cube[a][b][c]
                  + (b > 0? accSum[a][b-1][c] : 0)
                  + (c > 0? accSum[a][b][c-1] : 0)
                  - (b > 0 && c > 0? accSum[a][b-1][c-1] : 0);
            }
      
      ll ans = -INF;
      for (int l = 0; l < B; l++) for (int c = 0; c < C; c++)
         for (int i = l; i < B; i++) for (int j = c; j < C; j++) {
            // kadane nas A rsq's [(l,c) .. (i, j)]
            ll sum = 0;
            for (int a = 0; a < A; a++) {
               sum = max(rsq(a, l, c, i ,j), sum + rsq(a, l, c, i, j));
               ans = max(ans, sum);
            }
         }
      cout << ans << (T > 0? "\n\n": "\n");
   }
   return 0;
}