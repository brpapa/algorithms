/*
   ad-hoc > implementation
   difficulty: easy
   date: 03/Apr/2020
   by @brnpapa
*/
#include <iostream>
#include <set>
using namespace std;

int M[110][110];

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      int N; cin >> N;
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            cin >> M[i][j];
      
      int k = 0;
      for (int i = 0; i < N; i++) k += M[i][i];

      int r = 0;
      for (int i = 0; i < N; i++) {
         set<int> row;
         for (int j = 0; j < N; j++) row.insert(M[i][j]);
         if (row.size() != N) r++;
      }

      int c = 0;
      for (int j = 0; j < N; j++) {
         set<int> colum;
         for (int i = 0; i < N; i++) colum.insert(M[i][j]);
         if (colum.size() != N) c++;
      }

      printf("Case #%d: %d %d %d\n", t++, k, r, c);
   }
   return 0;
}