/*
   dynamic programming
   difficulty: easy
   date: 25/Jan/2020 
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

int memo[110][110];
int dp(int n, int k) {
   if (k == 1) return 1;
   
   int &ans = memo[n][k];
   if (ans != 0) return ans;

   for (int i = 0; i <= n; i++)
      ans = (ans + dp(n-i, k-1)) % (int)1e6;
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   memset(memo, 0, sizeof memo);

   while (true) {
      int N, K; cin >> N >> K;
      if (!N && !K) return 0;
      cout << dp(N, K) << endl;
   }
}
