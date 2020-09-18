/*
   dynamic programming
   difficulty: easy
   date: 16/Jan/2020 
   by: @brpapa
*/
#include <cstring>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

vector<int> prices[22]; // prices[c]: preços dos modelos da vestimenta c
int M, C;               // dinheiro disponível, vestimentas para comprar

int memo[22][210];
int dp(int c, int m) {
   // c: vestimenta atual
   // m: dinheiro restante

   if (m < 0) return -INF; // inviável
   if (c == C) return M-m; // total gasto
   
   int &ans = memo[c][m];
   if (ans != -1) return ans;
      
   for (int price : prices[c])
      ans = max(ans, dp(c+1, m-price));
      
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int N; cin >> N;
   while (N--) {
      cin >> M >> C;
      memset(memo, -1, sizeof(memo));
      for (int c = 0; c < C; c++) {
         int K; cin >> K;
         prices[c].resize(K);
         for (int &p : prices[c]) cin >> p;
      }
      int ans = dp(0, M);
      if (ans >= 0) cout << ans << endl;
      else cout << "no solution" << endl;
   }
   return 0;
}