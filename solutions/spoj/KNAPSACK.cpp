/*
   dynamic programming > 0-1 knapsack
   difficulty: easy
   date: 22/Oct/2019 
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define INF (1 << 30)
using namespace std;

int S, N;             // capacidade, qte de itens
int w[2020], v[2020]; // peso do item i, valor do item i

int memo[2020][2020];
int dp(int i, int s) {
	 // item i, mochila com capacidade s ainda disponível (carregando S-s)

   if (s < 0)  return -INF;
   if (i == N) return 0;

   int &ans = memo[i][s];
   if (ans != -1) return ans;

   return ans = max(
      dp(i+1, s),
      v[i] + dp(i+1, s-w[i])
   );
}

int main() {
   cin >> S >> N;
   for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

   memset(memo, -1, sizeof(memo));
   cout << dp(0, S);
   return 0;
}