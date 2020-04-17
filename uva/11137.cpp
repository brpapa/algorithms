/*
   dynamic programming > coin change (CC) > counting ways
   difficulty: easy
   date: 21/Feb/2020 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

vector<int> coins;

ll memo[25][10000];
ll cc(int c, int v) {
   // c-ésima moeda, valor restante para trocar v

   if (v == 0) return 1ll;
   if (v < 0 || c == coins.size()) return 0ll;

   ll &ans = memo[c][v];
   if (ans != -1) return ans;

   return ans = cc(c, v-coins[c]) + cc(c+1, v);
}

int main() {
   for (int c = 1; c <= 21; c++)
      coins.push_back(c*c*c);

   memset(memo, -1, sizeof memo); // pois as moedas não mudam
   int V;
   while (cin >> V)
      cout << cc(0, V) << endl;
   return 0;
}