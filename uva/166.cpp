/*
   dynamic programming > coin change
   difficulty: medium
   date: 15/May/2020
   problem: coin change with limited amount of coins + greedy coin change with unlimited amount of coins; I don't know why, but it works without memo
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int C = 6;

array<int, C> coins = {5, 10, 20, 50, 100, 200};
array<int, C> qtyCoins;
int V;

int greedy(int v) {
   int cnt = 0;
   for (int c = C-1; c >= 0; c--)
      cnt += v/coins[c], v %= coins[c];
   return cnt;
}

int solve(int c, int v, int qty) {
   // moeda atual coins[c], soma acumulada v e qty delas já foram usadas
   
   if (c == C)
      return (v < V)? INF : (qty + greedy(v-V)); // + troco do vendedor

   int ans = INF;
   for (int i = 0; i <= qtyCoins[c]; i++)
      ans = min(ans, solve(c+1, v + i*coins[c], qty+i));
   return ans;
}

int main() {
   while (true) {
      bool inv = true; 
      for (int &qty : qtyCoins) { cin >> qty; if (qty != 0) inv = false; }
      if (inv) break;

      int a, b; scanf("%d.%d", &a, &b);
      V = a*100 + b;

      printf("%3d\n", solve(0, 0, 0));
   }
   return 0;
}
