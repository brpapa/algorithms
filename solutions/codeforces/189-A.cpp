/*
   dynamic programming > coin change
   difficulty: easy
   date: 29/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
vector<int> pieces(3);

int memo[4004];
int dp(int n) {
   // pedaço atual com tamanho restante n

   if (n < 0) return -INF;
   if (n == 0) return 0;

   int &ans = memo[n];
   if (ans != -1) return ans;

   ans = -INF;
   for (int p : pieces) ans = max(ans, 1 + dp(n-p));
   return ans;
}

int main() {
   int n; cin >> n;
   for (int &p : pieces) cin >> p;
   memset(memo, -1, sizeof memo);
   cout << dp(n) << endl;
   return 0;
}
