/*
   dynamic programming > longest common subsequence (LCS)
   difficulty: easy
   date: 29/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> p;
string a; int N;
string b; int M;

int memo[2020][2020];
int dp(int i, int j) {
   // atual a[i] e b[j]

   if (i == N || j == M) return 0;

   int &ans = memo[i][j];
   if (ans != -1) return ans;

   if (a[i] == b[j])
      return ans = p[a[i]-'a'] + dp(i+1, j+1);
   
   return ans = max(dp(i+1, j), dp(i, j+1));
}

int main() {
   cin >> N >> M;
   p.resize(26); for (int &price: p) cin >> price;
   cin >> a >> b;

   memset(memo, -1, sizeof memo);
   cout << dp(0, 0) << endl;
   return 0;
}
