/*
   ad-hoc
   difficulty: none
   problem: pass the ball
   date: none
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int m[100][100], n;

int conta(int l, int c) {
   if (l < 0 || l >= n || c < 0 || c >= n)
      return 0;

   int soma = 1;
   int num = m[l][c];
   m[l][c] = 0; //bandeira já levantada

   if (m[l + 1][c] >= num)
      soma += conta(l + 1, c);
   if (m[l - 1][c] >= num)
      soma += conta(l - 1, c);
   if (m[l][c + 1] >= num)
      soma += conta(l, c + 1);
   if (m[l][c - 1] >= num)
      soma += conta(l, c - 1);
      
   return soma;
}
int main() {
   int lin, col;
   cin >> n >> lin >> col;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> m[i][j];

   printf("%d\n", conta(lin - 1, col - 1));
   return 0;
}