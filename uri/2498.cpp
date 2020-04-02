/*
   dynamic programming > 0-1 knapsack
   difficulty: easy
   date: 09/Sep/2019 
   by @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

int memo[1010][101];

int n, c; //qte de itens, capacidade
int wgt[1010], val[1010];

int ksTD(int i, int w) {
   //estado: item i, bolsa com capacidade disponível w

   if (i == n)
      return 0;

   int &m = memo[i][w];
   if (m != -1) return m;

   if (wgt[i] > w) //estouro da capacidade
      return m = ksTD(i+1, w);

   return m = max(
      ksTD(i+1, w),                  //não pega i
      val[i] + ksTD(i+1, w-wgt[i])   //pega i
   );
}

int main() {
   for (int t = 1; true; t++) {
      cin >> n >> c;
      if (n == 0 && c == 0) return 0;

      for (int i = 0; i < n; i++)
         cin >> wgt[i] >> val[i];

      memset(memo, -1, sizeof(memo));
      printf("Caso %d: %d\n", t, ksTD(0, c));
   }
}