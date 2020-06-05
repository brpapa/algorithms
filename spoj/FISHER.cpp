/*
   dynamic programming > 0-1 knapsack
   difficulty: medium
   date: 29/May/2020
   problem: get the (min) total value and total weight of the optimal knapsack
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
#define MAX_N 55
#define MAX_T 1001
typedef pair<int, int> ii;

int travelTime[MAX_N][MAX_N]; // tempo gasto para viajar i -> j
int tollPrice[MAX_N][MAX_N];  // preço do pedágio i -> j
int N, T;

// retorna o pair (tollPaid, timeNeeded) para ir da cidade n até N-1, com o menor tollPaid possível, e timeNeeded <= T
ii memo[MAX_N][MAX_T];
ii dp(int n, int t) {
   // cidade atual n, tempo restante t

   if (t < 0)    return ii(INF, INF); // inválido
   if (n == N-1) return ii(0, 0);

   ii &ans = memo[n][t];
   if (ans != ii(-1, -1)) return ans;
   
   ans = ii(INF, INF);
   // para cada cidade adjacente nn que não é a atual
   for (int nn = 0; nn < N; nn++) if (nn != n) {
      ii next = dp(nn, t-travelTime[n][nn]);

      if (next.first + tollPrice[n][nn] < ans.first) {
         ans = ii(
            next.first + tollPrice[n][nn],   // valor do pedágio
            next.second + travelTime[n][nn]  // tempo gasto
         );
      }
   }
   return ans;
}

int main() {
   while (cin >> N >> T && (N || T)) {
      for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> travelTime[i][j];
      for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> tollPrice[i][j];

      for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_T; j++) memo[i][j] = ii(-1, -1);
      ii ans = dp(0, T);
      cout << ans.first << " " << ans.second << endl;
   }
   return 0;
}
