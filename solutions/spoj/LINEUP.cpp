/*
   dynamic programming
   difficulty: easy
   date: 24/Oct/2020
   hint: use bitmask
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
const int N = 11;
int s[N][1 << N]; // s[i][j] = strength of i-th player on j-th position

vector<vector<int>> memo;
int dp(int i, int mask) {
   // player i, conjunto de posições já ocupadas mask

   if (i == N) return 0;
   if (mask == ((1 << N) -1)) return 0;

   int &ans = memo[i][mask];
   if (ans != -1) return ans;

   ans = -INF;
   for (int j = 0; j < N; j++)
      if (!(mask & (1 << j)) && s[i][j] > 0)
         ans = max(ans, s[i][j] + dp(i+1, mask | (1 << j)));

   return ans;
}

int main() {
   int T; cin >> T;
   while (T--) {
      for (int i = 0; i < 11; i++)
         for (int j = 0; j < 11; j++)
            cin >> s[i][j];

      memo.assign(N, vector<int>(1 << N, -1));
      cout << dp(0, 0) << endl;
   }
	return 0;
}
