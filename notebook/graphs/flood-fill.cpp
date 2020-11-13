/*
   Motivação: dado um grafo implícito como um 2D grid, onde células vizinhas em cada uma das 8 direções são consideradas adjacentes, encontre o tamanho do connect component que uma dada célula grid[sr][sc] faz parte.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
int sr = 2, sc = 1;
const int R = 9, C = 9;
char grid[R][C] = {
   {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'},
   {'L', 'L', 'W', 'W', 'L', 'L', 'W', 'L', 'L'},
   {'L', 'W', 'W', 'L', 'L', 'L', 'L', 'L', 'L'},
   {'L', 'W', 'W', 'W', 'L', 'W', 'W', 'L', 'L'},
   {'L', 'L', 'L', 'W', 'W', 'W', 'L', 'L', 'L'},
   {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'},
   {'L', 'L', 'L', 'W', 'W', 'L', 'L', 'W', 'L'},
   {'L', 'L', 'W', 'L', 'W', 'L', 'L', 'L', 'L'},
   {'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'L'},
};

// neighbors: S, SE, E, NE, N, NW, W, SW
int dr[8] = { 1,  1, 0, -1,-1, -1, 0,  1};
int dc[8] = { 0,  1, 1,  1, 0, -1,-1, -1}; 

int walk(int r, int c, char look_for, char replace_by) {
   if (r < 0 || r == R || c < 0 || c == C) return 0;
   if (grid[r][c] != look_for) return 0;

   // rotula a célula atual para evitar que seja visitada novamente
   grid[r][c] = replace_by;

   int ans = 1;                  // conta a célula (r,c)
   for (int d = 0; d < 8; d++) { // para cada célula (nr, nc) adjacente à (r,c)
      int nr = r+dr[d];
      int nc = c+dc[d];
      ans += walk(nr, nc, look_for, replace_by);
  }
   return ans;
}

int main() {
   cout << walk(sr, sc, grid[sr][sc], '.') << endl; 
   return 0;
}