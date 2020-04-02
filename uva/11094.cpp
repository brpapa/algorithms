/*
   graphs > traversal > flood fill
   difficulty: easy
   date: 31/Jan/2020 
   by @brnpapa
*/
#include <iostream>
using namespace std;

int R, C;
char grid[22][22];

int dr[4] = {1, 0,-1, 0};
int dc[4] = {0, 1, 0,-1};

int floodFill(int r, int c, char target, char checked) {
   if (c == -1) c = C-1;
   if (c == C) c = 0;

   if (r < 0 || r == R || grid[r][c] != target)
      return 0;

   grid[r][c] = checked;

   int ans = 1;
   for (int d = 0; d < 4; d++)
      ans += floodFill(r+dr[d], c+dc[d], target, checked);
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   while (cin >> R >> C) {
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++)
            cin >> grid[r][c];
      
      int x, y; cin >> x >> y;

      char target = grid[x][y];
      floodFill(x, y, target, ' '); // invalida o componente conectado em que ele já está

      int ans = 0;
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++) 
            ans = max(ans, floodFill(r, c, target, ' '));
      cout << ans << endl;
   }
   return 0;
}
