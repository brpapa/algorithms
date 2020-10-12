/* 
   0-1 Knapsack

   Motivação: dado os valores v e pesos w de N itens, determine o valor total máximo que a mochila pode carregar selecionando um subconjunto desses itens, de modo que a soma de seus pesos não exceda a capacidade máxima S.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
int N, S;
vector<int> v; // v[i]: valor do item i
vector<int> w; // w[i]: peso do item i

/* */
vector<vector<int>> memo; // N x (S+1)

/* O(N*S) */
int dp(int i, int s) {
   // item i, mochila com capacidade disponível s (carregando S-s)

   if (s < 0)  return -INF; // inválido
   if (i == N) return 0;

   int &ans = memo[i][s];
   if (ans != -1) return ans;

   return ans = max(
      dp(i+1, s),              // não pega i
      v[i] + dp(i+1, s-w[i])   // pega i
   );
}

/* e.g. */
int main() {
   N = 4, S = 12;
   v = { 100, 70, 50, 10 };
   w = { 10, 4, 6, 12 };

   memo.assign(N, vector<int>(S+1, -1));
   cout << dp(0, S) << endl; // 120

   return 0;
}

// se S é muito grande, tal que N*S >>> 10^6, essa solução não é viável, mesmo com space saving

// abordagem top-down é mais rápida que bottom-up, pois nem sempre todos os estados são visitados.