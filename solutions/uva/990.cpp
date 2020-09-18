/*
   dynamic programming > 0-1 knapsack
   difficulty: easy
   date: 14/May/2020
   problem: with recovering
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int INF = 1 << 30;
const int MAX_N = 33;
const int MAX_T = 1010;

int T, W, N;
int d[MAX_N], v[MAX_N];

int memo[MAX_N][MAX_T];
int dp(int n, int t) {
   // tesouro atual n, t segundos sob a água já gastos

   if (t >= T) return -INF;
   if (n == N) return 0;

   int &ans = memo[n][t];
   if (ans != -1) return ans;
   
   return ans = max(
      v[n] + dp(n+1, t + 3*W*d[n]),
      dp(n+1, t)
   );
}

int main() {
   int t = 0;
   while (cin >> T >> W) {
      if (t++ != 0) cout << endl;
      cin >> N; for (int n = 0; n < N; n++) cin >> d[n] >> v[n];

      memset(memo, -1, sizeof memo);
      cout << dp(0, 0) << endl;

      vector<ii> recovered;
      for (int n = 0, t = 0; n < N; n++)
         if (v[n] + dp(n+1, t + 3*W*d[n]) >= dp(n+1, t)) {
            recovered.push_back(ii(d[n], v[n]));
            t += 3*W*d[n];
         }
      cout << recovered.size() << endl;
      for (ii rec : recovered) cout << rec.first << " " << rec.second << endl;
   }
   return 0;
}
