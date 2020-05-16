/*
   dynamic programming > 0-1 knapsack > subset sum
   difficulty: medium
   date: 15/May/2020
   problem: find the smallest sum s of a subset of A, s >= S
   hint: scan as "%d.%d"
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

vector<int> A;
int S;

// retorna a menor soma entre elementos de A, mas que seja >= S
int memo[101][5001];
int dp(int i, int s) {
   // i-ésimo número de A, soma s do subconjunto atual

   if (s >= S) return s;
   if (i == A.size()) return INF; // inválido

   int &ans = memo[i][s];
   if (ans != -1) return ans;

   return ans = min(dp(i+1, s+A[i]), dp(i+1, s));
}

int main() {
   int N, x;
   while (cin >> N >> x && (N || x)) {
      A.clear(); x--;
      int me;
      for (int n = 0; n < N; n++) {
         int a, b; scanf("%d.%d", &a, &b); int c = a*100 + b;
         if (n == x) me = c;
         else A.push_back(c);
      }

      S = 5001 - me; // faltante até alcançar 50.01%
      memset(memo, -1, sizeof memo);

      int num = me*100;
      int den = me + dp(0, 0);
      printf("%.2f\n", (double)num/den);
   }   
   return 0;
}
