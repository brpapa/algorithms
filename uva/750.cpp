/*
   brute force > iterative > all permutations
   difficulty: easy
   problem: 8 queens chess problem
   date: 12/Jan/2020
   author: @brnpapa
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define abs(a) ((a) > 0 ? (a) : -(a))
using namespace std;

struct Taux {
   int row[8]; // row[c]: linha da rowuna c
};
vector<Taux> validArrangements;

int main() {
   // pré-processa todas as disposições válidas (q nao compartilham diagonais)
   int row[8] = {0, 1, 2, 3, 4, 5, 6, 7};
   do {
      bool valid = true;
      for (int i = 0; i < 8 && valid; i++)
         for (int j = i+1; j < 8 && valid; j++)
            if (abs(i-j) == abs(row[i]-row[j]))
               valid = false;
               
      if (valid) {
         Taux tmp; for (int i = 0; i < 8; i++) tmp.row[i] = row[i];
         validArrangements.push_back(tmp);
      }
   } while (next_permutation(row, row+8));

   int T; scanf("%d", &T);
   while (T--) {
      int r0, c0; scanf("%d %d", &r0, &c0); r0--; c0--;

      int s = 1;
      printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
      for (Taux va : validArrangements)
         if (va.row[c0] == r0) {
            printf("%2d     ", s++);
            for (int c = 0; c < 8; c++)
               printf(" %d", va.row[c]+1);
            printf("\n");
         }
      printf("%s", T > 0? "\n" : "");
   }
   return 0;
}
