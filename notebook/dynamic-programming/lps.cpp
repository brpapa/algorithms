/*
   Motivation: given a sequence, find the length of the LPS in it.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
string A = "GEEKSFORGEEKS"; int N = A.size();

vector<vector<int>> memo;

/* O(N^2) */
int dp(int l, int r) {
   // substring A[l..r]

   if (l > r) return 0;
   if (l == r) return 1;

   int &ans = memo[l][r];
   if (ans != -1) return ans;

   if (A[l] == A[r]) return ans = 2 + dp(l+1, r-1);
   return ans = max(dp(l+1, r), dp(l, r-1));
}

int main() {
   memo.assign(N, vector<int>(N, -1));
   cout << dp(0, N-1) << endl;
}