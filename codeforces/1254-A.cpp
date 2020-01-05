/*
   ad-hoc > implementation
   difficulty: medium
   problem: feeding chicken
   date: 25/Nov/2019
   author: @brnpapa
*/
#include <iostream>
using namespace std;

string chickens = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char farm[101][101];
char ans[101][101];

int main() {
   int T;
   cin >> T;

   while (T--) {
      int R, C, K;
      cin >> R >> C >> K;

      char tmp;
      int qtyRiceCells = 0;
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++) {
            cin >> tmp;
            farm[r][c] = tmp;
            if (tmp == 'R')
               qtyRiceCells++;
         }

      int more_qtyChickens = qtyRiceCells % K;
      int more_qtyCells = qtyRiceCells/K + 1;
      // cout << more_qtyChickens << " galinhas recebem " << more_qtyCells << " células" << endl;

      int less_qtyChickens = K - more_qtyChickens; 
      int less_qtyCells = qtyRiceCells/K;
      // cout << less_qtyChickens << " galinhas recebem " << less_qtyCells << " células" << endl;

      int k = 0;   // galinha atual
      int qty = 0; // quantas celulas de arroz a galinha atual recebeu

      for (int r = 0; r < R; r++) {
         bool rEven = r%2 == 0;

         for (int c = rEven? 0:C-1; rEven? c < C:c >= 0; c += rEven? 1:-1) {
            int qtyCells = (k < more_qtyChickens)? more_qtyCells : less_qtyCells; // as more_qtyChickens primeiras galinhas são as que recebem more_qtyCells células

            if (farm[r][c] == 'R') {
               if (++qty > qtyCells) {
                  qty = 1;
                  k++;
               }
            }
            ans[r][c] = chickens[k];
         }
      }

      for (int r = 0; r < R; r++) {
         for (int c = 0; c < C; c++)
            cout << ans[r][c];
         cout << endl;
      }
   }
   return 0;
}