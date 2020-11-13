/*
   dynamic programming > longest palindromic subsequence (LPS)
   difficulty: easy
   date: 06/Nov/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string A; int N;
vector<vector<int>> memo;

int dp(int l, int r) {
   if (l == r) return 1;
   if (l > r) return 0;

   int &ans = memo[l][r];
   if (ans != -1) return ans;

   if (A[l] == A[r]) return ans = 2 + dp(l+1, r-1);
   return ans = max(dp(l+1, r), dp(l, r-1));
}

int main() {
   int T; cin >> T;
   cin.ignore();
   while (T--) {
      getline(cin, A); N = A.size();
      memo.assign(N, vector<int>(N, -1));
      cout << dp(0, N-1) << endl;
   }
	return 0;
}
