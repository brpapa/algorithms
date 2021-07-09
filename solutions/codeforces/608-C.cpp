/*
   dynamic programming
   difficulty: medium
   date: 01/Nov/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX_POS = 1e6 + 6;

map<int, int> power; // power[pos] = power level do beacon da posição pos

int main() {
   int N; cin >> N;
   for (int i = 0; i < N; i++) {
      int pos; cin >> pos;
      cin >> power[pos];
   }

   vector<int> dp(MAX_POS); // dp[pos] = qte max de beacons não destruídos posicionados em [0..pos]
   dp[0] = power[0]? 1 : 0;

   int max_dp = 0;
   for (int pos = 1; pos < MAX_POS; pos++) {
      dp[pos] = 
         power[pos] == 0
            ? dp[pos-1] 
            : pos-power[pos]-1 >= 0
               ? 1 + dp[pos-power[pos]-1] // liga beacon que está em pos
               : 1;

      max_dp = max(max_dp, dp[pos]);
   }

   cout << (N - max_dp) << endl;
   return 0;
}
