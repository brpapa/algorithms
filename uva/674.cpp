/*
   dynamic programming > coin change (CC) > counting ways
   difficulty: easy
   date: 23/Jan/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
int coins[N] = {1, 5, 10, 25, 50};

int memo[5][7500];
int cc(int i, int v) {
   // estado: moeda i, valor restante v para ser trocado

   if (v == 0) return 1;
   if (v < 0 || i == N) return 0;

   int &ans = memo[i][v];
   if (ans != -1) return ans;
   
   return ans = cc(i+1, v) + cc(i, v-coins[i]);
}

int main() {
   memset(memo, -1, sizeof(memo));
   
   int V;
   while (cin >> V)
      cout << cc(0, V) << endl;
   return 0;
}
