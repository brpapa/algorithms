/*
   dynamic programming
   difficulty: medium
   date: 30/Apr/2020
   hint: use space saving + all divisors in O(sqrt(n)) to optimize
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

/*
int dp(int i, int j) {
   // i-ésimo número de A, subsequência boa atual de tamanho j

   if (i == N) return j > 0;

   if (A[i] % (j+1) == 0) // A[i] pode fazer parte da subsequencia boa?
      return dp(i+1, j) + dp(i+1, j+1);

   return dp(i+1, j);
}
*/

// todos os divisores em ordem crescente de n em O(sqrt(n))
vector<int> allDivs(int n) {
   vector<int> divs, greaters;
   for (int i = 1; i*i <= n; i++) {
      if (n%i) continue;

      divs.push_back(i);
      if (n/i != i) greaters.push_back(n/i);
   }
   for (int i = greaters.size()-1; i >= 0; i--)
      divs.push_back(greaters[i]);

   return divs;
}


int main() {
   int N; cin >> N;
   vector<int> A(N); for (int &a : A) cin >> a;

   int dp[100010];
   for (int j = 0; j <= N; j++) dp[j] = j > 0;

   for (int i = N-1; i >= 0; i--) {
      // O(sqrt(N))
      for (int j : allDivs(A[i]))
         if (j-1 <= i)
            dp[j-1] = (dp[j-1] + dp[j]) % MOD;

      // O(N)
      // for (int j = 0; j <= i; j++)
      //    if (A[i] % (j+1) == 0) 
      //       dp[j] = (dp[j] + dp[j+1]) % MOD;
   }
   cout << dp[0] << endl;
   return 0;
}
