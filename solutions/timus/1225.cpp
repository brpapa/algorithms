/*
   dynamic programming
   difficulty: easy
   date: 01/Nov/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

enum { WHITE, RED };
int N;

vector<ll> memo;

ll dp(int n) {
   if (n == N) return 1ll;
   if (n > N) return 0ll;

   ll &ans = memo[n];
   if (ans != -1) return ans;

   return ans = dp(n+1) + ((n+2 < N)? dp(n+2) : 0);
}

int main() {
   cin >> N;

   memo.assign(N, -1);
   ll ans = 2 * dp(0);
   cout << ans << endl;

   return 0;
}