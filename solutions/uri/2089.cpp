/*
   dynamic programming > subset sum
   difficulty: medium
   date: 15/Oct/2020
   hint: optimize memory
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int V, N; 
   while (cin >> V >> N && (V || N)) {
      vector<int> coins(N); for (int &coin : coins) cin >> coin;

      vector<vector<bool>> dp(2, vector<bool>(V+1, false));

      for (int i = N; i >= 0; i--) dp[i%2][0] = true;

      for (int i = N-1; i >= 0; i--)
         for (int v = 1; v <= V; v++)
            dp[i%2][v] = dp[(i+1)%2][v] || ((v-coins[i] >= 0)? dp[(i+1)%2][v-coins[i]] : false);

      cout << (dp[0%2][V]? "sim" : "nao") << endl;
   }
   return 0;
}
