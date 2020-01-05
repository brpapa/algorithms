/*
   mathematics > combinatorics > combinations > binomial coefficient
   difficulty: easy
   problem: rectangles
   date: 27/Dec/2019
   author: @brnpapa
*/
#include <cmath>
#include <iostream>
#define MAX 50
using namespace std;
typedef long long int lli;

int main() {
   int R, C;
   cin >> R >> C;

   int t[MAX][MAX];
   for (int r = 0; r < R; r++)
      for (int c = 0; c < C; c++)
         cin >> t[r][c];

   lli ans = 0;
   for (int r = 0; r < R; r++) {
      int qty[2] = {0, 0};
      for (int c = 0; c < C; c++)
         qty[t[r][c]]++;

      ans += (lli)pow(2, qty[0]) - 1;
      ans += (lli)pow(2, qty[1]) - 1;
   }
   for (int c = 0; c < C; c++) {
      int qty[2] = {0, 0};
      for (int r = 0; r < R; r++)
         qty[t[r][c]]++;

      ans += (lli)pow(2, qty[0]) - 1;
      ans += (lli)pow(2, qty[1]) - 1;
   }
   ans -= R * C; // conjuntos de 1 elemento

   cout << ans << endl;
   return 0;
}