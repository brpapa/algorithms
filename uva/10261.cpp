/*
   dynamic programming > 0-1 knapsack
   difficulty: medium
   date: 15/May/2020
   problem: as if there were 2 knapsacks to fill at the same time; with recovering
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int MAX_L = 10001;
const int MAX_C = 202;

int cars[MAX_C]; int C;

int memo[MAX_C][MAX_L];
int dp(int c, int reml, int remr) {
   // carro atual c, restando reml na esquerda e remr na direita
   
   if (c == C) return 0;

   int &ans = memo[c][reml];
   if (ans != -1) return ans;

   int l = -1, r = -1;
   if (reml >= cars[c]) l = dp(c+1, reml-cars[c], remr);
   if (remr >= cars[c]) r = dp(c+1, reml, remr-cars[c]);

   // anula se não for possível embarcar esse carro (c) em nenhum dos 2 lados
   return ans = (l == -1 && r == -1)? 0 : (1 + max(l, r));
}

void recover(int L) {
   int reml = L, remr = L;
   for (int c = 0; c < C; c++) {
      int l = -1, r = -1;
      if (reml >= cars[c]) l = dp(c+1, reml-cars[c], remr);
      if (remr >= cars[c]) r = dp(c+1, reml, remr-cars[c]);
      if (l == -1 && r == -1) break;

      if (l >= r) {
         cout << "port" << endl;
         reml -= cars[c];
      } else {
         cout << "starboard" << endl;
         remr -= cars[c];
      }
   }
}

int main() {
   int t = 0, T; cin >> T;
   while (T--) {
      if (t++ > 0) cout << endl;
      int L; cin >> L; L *= 100;
      for (C = 0; true; C++) {
         int len; cin >> len; if (len == 0) break;
         cars[C] = len;
      }

      memset(memo, -1, sizeof memo);
      cout << dp(0, L, L) << endl;
      recover(L);
   }
   return 0;
}
