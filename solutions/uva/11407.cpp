/*
   dynamic programming > coin change
   difficulty: easy
   date: 14/May/2020
   hint: consider the coins as the perfect squares
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int memo[10010];
int dp(int n) {
   // valor restante n

   if (n == 0) return 0;

   int &ans = memo[n];
   if (ans != -1) return ans;

   ans = 1 << 30;
   for (int i = 1; n-i*i >= 0; i++)
      ans = min(ans, 1 + dp(n-i*i));

   return ans;
}

int main() {
   memset(memo, -1, sizeof memo); // o conjunto dos quadrados perfeitos nunca muda

   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      cout << dp(N) << endl;
   }
   return 0;
}
