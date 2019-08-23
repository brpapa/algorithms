/*
   dynamic programming | knapsack
   problem: the knapsack problem
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

int memo[2020][2020];
int s, n; //capacidade, qte de itens
int wgt[2020], val[2020]; //tamanho do item i, valor do item i

int knapsack(int i, int w) {
   //estado: item i, mochila com capacidade disponível w
   
   if (i == n) 
      return 0;

   if (memo[i][w] != -1)
      return memo[i][w];

   if (wgt[i] > w) 
      return memo[i][w] = knapsack(i+1, w); //estourará capacidade, logo não pega i

   return memo[i][w] = max(
      knapsack(i+1, w), //não pega i
      val[i] + knapsack(i+1, w - wgt[i]) //pega i
   );
}

int main() {
   cin >> s >> n;
   for (int i = 0; i < n; i++)
      cin >> wgt[i] >> val[i];

   memset(memo, -1, sizeof(memo));
   cout << knapsack(0, s);
   return 0;
}