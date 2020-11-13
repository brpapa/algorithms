/*
   Motivação: dado duas sequências A[0..N-1] e B[0..M-1], encontre o comprimento da maior subsequência comum entre elas.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
string A = "abcde"; int N = 5;
string B = "adce"; int M = 4;

vector<vector<int>> memo;

/* O(N*M) */
int lcs0(int i, int j) {
   // i-ésima posição em A, j-ésima posição em B
   
   if (i == N || j == M) return 0;

   int &ans = memo[i][j];
   if (ans != -1) return ans;

   if (A[i] == B[j])
      return ans = 1+lcs0(i+1, j+1);

   return ans = max(lcs0(i+1, j), lcs0(i, j+1));
}

/* O(N*M) */
int lcs1() {
   vector<vector<int>> dp(N+1, vector<int>(M+1));

   for (int i = 0; i <= N; i++) dp[i][M] = 0;
   for (int j = 0; j <= M; j++) dp[N][j] = 0;

   for (int i = N-1; i >= 0; i--)
      for (int j = M-1; j >= 0; j--) {
         if (A[i] == B[j])
            dp[i][j] = 1 + dp[i+1][j+1];
         else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
      }
   
   return dp[0][0];
}


int main() {
   memo.assign(N, vector<int>(M, -1));
   cout << lcs0(0, 0) << endl;
   // cout << lcs1() << endl;
   return 0;
}
