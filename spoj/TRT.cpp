/*
   dynamic programming
   difficulty: easy
   date: 29/Apr/2020
   hint: don't memoize the current day
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> A; int N;

int memo[2020][2020];
int dp(int l, int r) {
   int d = l+(N-r); // dia atual
   
   if (l == r) return A[l]*d;

   int &ans = memo[l][r];
   if (ans != -1) return ans;

   return ans = max(
      A[l]*d + dp(l+1, r),
      A[r]*d + dp(l, r-1)
   );
}

int main() {
   cin >> N;
   A.resize(N); for (int &a: A) cin >> a;

   memset(memo, -1, sizeof memo);
   cout << dp(0, N-1) << endl;
   return 0;
}
