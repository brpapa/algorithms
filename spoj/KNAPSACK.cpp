/*
   dynamic programming > knapsack
   problem: the knapsack problem
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

int memo[2020][2020];

int s, n; //capacidade, qte de itens
int wgt[2020], val[2020]; //peso do item i, valor do item i

int ksTD(int i, int w) {
   //estado: item i, mochila com capacidade disponível w
   
   if (i == n) 
      return 0;

   int &m = memo[i][w];
   if (m != -1) return m;

   if (wgt[i] > w) 
      return m = ksTD(i+1, w); //estourará capacidade, logo não pega i

   return m = max(
      ksTD(i+1, w),                 //não pega i
      val[i] + ksTD(i+1, w-wgt[i])  //pega i
   );
}

int main() {
   cin >> s >> n;
   for (int i = 0; i < n; i++)
      cin >> wgt[i] >> val[i];

   memset(memo, -1, sizeof(memo));
   cout << ksTD(0, s);
   return 0;
}