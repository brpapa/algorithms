/*
   dynamic programming > longest common subsequence (LCS)
   difficulty: none
   problem: longest common subsequence
   date: none
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;

int memo[1010][1010];
string a, b;

int lcsTD(int i, int j) {
   //estado: indice i de a, indice j de b

   if (i == a.size() || j == b.size())
      return 0;

   int &m = memo[i][j];
   if (m != -1) return m;

   if (a[i] == b[j])
      return m = 1+lcsTD(i+1, j+1);

   return m = max(
      lcsTD(i+1, j),
      lcsTD(i, j+1)
   );
}

//preenche tab de baixo para cima, da direita para a esquerda
int lcsBU() {
   int tab[1010][1010]; //tabulation

   for (int i = a.size(); i >= 0; i--) {
      for (int j = b.size(); j >= 0; j--) {
         
         if (i == a.size() || j == b.size()) //casos base
            tab[i][j] = 0;

         else if (a[i] == b[j])
            tab[i][j] = 1+tab[i+1][j+1];
         else {
            tab[i][j] = max(
               tab[i+1][j],
               tab[i][j+1]
            );
         }
      }
   }
   return tab[0][0];
}

int main() {
   while (getline(cin, a) && getline(cin, b)) {
      // memset(memo, -1, sizeof(memo)); //caro para >>> 1010
      // cout << lcsTD(0,0) << endl;
      
      cout << lcsBU() << endl;
   }
   return 0;
}