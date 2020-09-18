/*
   graphs > specials > tree
   difficulty: easy
   date: 27/May/2020
   problem: compute the diameter of a given implicit tree
   by: @brpapa
*/
#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITING 1
using namespace std;

char grid[1001][1001]; int R, C;
int state[1001][1001];

bool isValid(int r, int c) {
   if (r < 0 || r >= R || c < 0 || c >= C) return false;
   if (grid[r][c] == '#') return false;
   return true;
}

int dr[4] = {1, 0,-1, 0};
int dc[4] = {0, 1, 0,-1};
int lr, lc;

int maxLvl;
void dfs(int r, int c, int lvl) {
   if (lvl > maxLvl) { maxLvl = lvl; lr = r, lc = c; }
   state[r][c] = VISITING;

   for (int d = 0; d < 4; d++) {
      int nr = r+dr[d];
      int nc = c+dc[d];
      if (isValid(nr, nc) && state[nr][nc] == UNVISITED)
         dfs(nr, nc, lvl+1);
   }
}

int main() {
   int T; cin >> T;
   while (T--) {
      cin >> C >> R;
      int ur = -1, uc = -1;
      for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
         cin >> grid[r][c];
         if (grid[r][c] == '.' && ur == -1 && uc == -1) ur = r, uc = c;
      }

      maxLvl = 0;
      memset(state, UNVISITED, sizeof state);
      dfs(ur, uc, 0); // set (lr,lc) como o nó mais distante de (ur, uc)

      maxLvl = 0;
      memset(state, UNVISITED, sizeof state);
      dfs(lr, lc, 0);
      printf("Maximum rope length is %d.\n", maxLvl);
   }
   return 0;
}
