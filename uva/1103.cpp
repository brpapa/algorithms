/*
   graphs > traversal > flood fill
   difficulty: hard
   date: 01/Feb/2020 
   hint: consider each pixel as a vertex of an implicit graph, then identify each hieroglyph counting the number of white CCs within it
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x7f7f7f7f
#define WHITE -1
#define BLACK -2
#define CHECKED -3

int R, C;
int grid[222][222];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int floodFill(int r, int c, int lookFor, int replaceBy) {
   if (r < 0 || r > R || c < 0 || c > C)
      return INF; // não extourou em figura, deve ser prioridade
   if (grid[r][c] != lookFor)
      return grid[r][c]; // id da figura em que extourou

   grid[r][c] = replaceBy;

   int ans = -1;
   for (int d = 0; d < 4; d++)
      ans = max(ans, floodFill(r+dr[d], c+dc[d], lookFor, replaceBy));
   return ans;
}

int main() {
   int T = 0;
   while (cin >> R >> C) {
      if (!R && !C) break; C *= 4;
      memset(grid, WHITE, sizeof(grid));

      string str;
      for (int r = 0; r < R; r++) {
         cin >> str;
         for (int c = 0; c < C/4; c++) {
            int mask = stoi(string(1, str[c]), 0, 16);

            for (int i = 0; i < 4; i++)
               if (mask & (1 << i)) grid[r][4*c+3-i] = BLACK;
         }
      }

      // identifica cada figura (borda) com um número >= 0
      int N = 0;
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++)
            if (grid[r][c] == BLACK)
               floodFill(r, c, BLACK, N++);

      vector<int> internalCC(N, 0); // internalCC[n]: quantidade de componentes conectados dentro da figura n
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++)
            if (grid[r][c] == WHITE) {
               int n = floodFill(r, c, WHITE, CHECKED);
               if (n != INF) internalCC[n]++; // não é white do background
            }

      vector<char> ans;
      for (int qty : internalCC) {
         switch (qty) {
            case 1: ans.push_back('A'); break;
            case 3: ans.push_back('J'); break;
            case 5: ans.push_back('D'); break;
            case 4: ans.push_back('S'); break;
            case 0: ans.push_back('W'); break;
            case 2: ans.push_back('K'); break;
         }
      }
      cout << "Case " << (++T) << ": ";
      sort(ans.begin(), ans.end());
      for (char c : ans) cout << c; cout << endl;
   }   
   return 0;
}
