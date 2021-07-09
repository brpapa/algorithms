/* 
   Motivação: dado os valores de N moedas, quantas moedas, no mínimo, representam exatamente V centavos? Assume-se que há suprimento ilimitado de qualquer moeda.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
int N = 4, V = 7;
vector<int> coins = {1, 3, 4, 5};

vector<int> memo;

/* O(N*V) - retorna a quantidade mínima de moedas que representa v centavos */
int dp(int v) {
   // v centavos restantes para serem trocados

   if (v == 0) return 0;
   if (v < 0)  return INF; // inválido

   int &ans = memo[v];
   if (ans != -1) return memo[v];

   ans = INF;
   for (int coin : coins)
      ans = min(ans, 1 + dp(v-coin));

   return ans;
}

int main() {
   memo.assign(V+1, -1);  // resetar apenas se moedas mudarem, e não V
   cout << dp(V) << endl;
   return 0;
}
