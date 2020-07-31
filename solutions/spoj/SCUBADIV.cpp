/*
   dynamic programming > 0-1 knapsack
   difficulty: easy
   date: 29/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

struct T {
   int qtyOx, qtyNi, w;
   T() {}
};
vector<T> A; int N;

int memo[1010][22][80];
int dp(int n, int ox, int ni) {
   // cilindro atual A[n], demanda por uma qte ox e ni de oxigênio e nitrogênio

   if (ox <= 0 && ni <= 0) return 0;
   if (n == N) return 1 << 30;

   int &ans = memo[n][max(ox, 0)][max(ni, 0)];
   if (ans != -1) return ans;

   return ans = min(
      A[n].w + dp(n+1, ox-A[n].qtyOx, ni-A[n].qtyNi),
      dp(n+1, ox, ni)
   );
}

int main() {
   int c;
   cin >> c;
   while (c--) {
      int ox, ni; cin >> ox >> ni >> N;
      A.resize(N); for (T &a : A) cin >> a.qtyOx >> a.qtyNi >> a.w;

      memset(memo, -1, sizeof memo);
      cout << dp(0, ox, ni) << endl;
   }
   return 0;
}
