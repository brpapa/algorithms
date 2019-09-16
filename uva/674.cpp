/*
   dynamic programming | coins ways
   problem: coin change
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;
#define QTY_COINS 5

int memo[5][7500];
int coins[QTY_COINS] = {1, 5, 10, 25, 50};

int ccTD(int i, int v) {
   //estado: moeda i, valor restante v para ser trocado

   if (v == 0)
      return 1;
   else if (v < 0 || i == QTY_COINS)
      return 0;

   int &m = memo[i][v];
   if (m != -1) return m;
   
   return m = ccTD(i, v-coins[i]) + ccTD(i+1, v);
}

int main() {
   int v;

   while (cin >> v) {
      memset(memo, -1, sizeof(memo));
      cout << ccTD(0, v) << endl; //qte de trocos possíveis
   }
   return 0;
}
