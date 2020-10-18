/*
   dynamic programming
   difficulty: easy
   date: 17/Oct/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

vector<int> A; int N;

vector<vector<int>> memo;
int dp(int i, int k) {
   if (k < 0) return -INF;
   if (i >= N) return 0;

   int &ans = memo[i][k];
   if (ans != -1) return ans;

   return ans = max(dp(i+1, k), A[i] + dp(i+2, k-A[i]));
}

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      int K; cin >> N >> K;
      A.resize(N); for (int &a : A) cin >> a;

      memo.assign(N, vector<int>(K+1, -1));
      cout << "Scenario #" << (t++) << ": " << dp(0, K) << endl;
   }
	return 0;
}
