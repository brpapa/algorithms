/*
   brute force > recursive backtracking
   difficulty: medium
   date: 19/Mar/2020
   problem: solve the sudoku puzzle
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define MAX 9 // max n^2
using namespace std;

int n;
int board[MAX][MAX];
bool changeable[MAX][MAX];  // posição de board livre para alteração
bool hasSolution;

bool usedOnRow[MAX][MAX+1]; // usedOnRow[r][num]: num foi usado na linha r?
bool usedOnCol[MAX][MAX+1]; // usedOnCol[c][num]: num foi usado na coluna c?
bool usedOnBox[MAX][MAX+1]; // usedOnBox[b][num]: num foi usado no bloco b?

void markUsedAs(bool used, int r, int c, int num) {
   usedOnRow[r][num] = used;
   usedOnCol[c][num] = used;
   int b = n*(r/n) + c/n;
   usedOnBox[b][num] = used;
}

void bt(int i) {
   int r = i/(n*n), c = i%(n*n);
   // define board[r][c] com algum num possível

   if (hasSolution) return;

   if (i == (n*n)*(n*n)) {
      hasSolution = true;
      for (int r = 0; r < n*n; r++) {
         for (int c = 0; c < n*n-1; c++)
            cout << board[r][c] << " ";
         cout << board[r][n*n-1] << endl;
      }
      return;
   }

   int b = n*(r/n) + c/n; // (r,c) está na box b

   if (!changeable[r][c]) bt(i+1);
   else {
      for (int num = 1; num <= n*n; num++) 
         if (!usedOnRow[r][num] && !usedOnCol[c][num] && !usedOnBox[b][num]) {
            board[r][c] = num;

            markUsedAs(1, r, c, num);
            bt(i+1);
            markUsedAs(0, r, c, num);
         }
   }
}

int main() {
   int t = 0;
   while (cin >> n) {
      memset(usedOnRow, 0, sizeof usedOnRow);
      memset(usedOnCol, 0, sizeof usedOnCol);
      memset(usedOnBox, 0, sizeof usedOnBox);
      hasSolution = false;

      for (int r = 0; r < n*n; r++)
         for (int c = 0; c < n*n; c++) {
            cin >> board[r][c];
            markUsedAs(1, r, c, board[r][c]);
            changeable[r][c] = board[r][c] == 0;
         }

      if (t++ > 0) cout << endl;
      bt(0);
      if (!hasSolution) cout << "NO SOLUTION" << endl;
   }
   return 0;
}
