/*
   dynamic programming > edit distance
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <cstring>
using namespace std;
#define min3(a, b, c) ((a)<(b) ? min(a, c):min(b, c))

int memo[2020][2020];
string a, b;

int edTD(int i, int j) {
   //estado: letras a[i] e b[j]

   if (i == -1)
      return j+1; //insere todas as letras restantes de b em a
   if (j == -1)
      return i+1; //insere todas as letras restantes de a em b

   int &m = memo[i][j];
   if (m != -1) return m;

   if (a[i] == b[j])
      return m = edTD(i-1, j-1);

   return m = 1 + min3(
      edTD(i-1, j),     //deleta a[i]
      edTD(i, j-1),     //insere b[j] em a[i]
      edTD(i-1, j-1)    //substitui a[i] por b[j]
   );
}

int main() {
   int T;
   cin >> T;

   while (T--) {
      cin >> a >> b;

      memset(memo, -1, sizeof(memo));
      cout << edTD(a.size()-1, b.size()-1) << endl;
   }
   return 0;
}