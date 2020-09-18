/*
   graphs > traversal > edge classification
   difficulty: easy
   date: 18/May/2020
   problem: check if a given implicit undirected graph has a cycle of length >= 4
   by: @brpapa
*/
#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITING 1
using namespace std;
typedef pair<int, int> ii;

int grid[55][55];
int R, C;

int state[55][55];
map<ii, ii> parent;

string ans;

int dr[4] = {1, 0,-1, 0};
int dc[4] = {0, 1, 0,-1};
void dfs(int r, int c) {
   if (ans == "Yes") return;

   state[r][c] = VISITING;

   // para cada aresta (r,c) --> (nr,nc)
   for (int d = 0; d < 4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (grid[nr][nc] != grid[r][c]) continue; // não é da mesma cor

      if (state[nr][nc] == UNVISITED) {
         parent[ii(nr, nc)] = ii(r, c);
         dfs(nr, nc);
      }
      else if (state[nr][nc] == VISITING && parent[ii(r,c)] != ii(nr, nc)) {
         int lenCycle = 0;
         for (ii curr = ii(nr, nc); curr != ii(-1, -1); curr = parent[curr]) lenCycle++;
         if (lenCycle >= 4) ans = "Yes";
      }
   }
}

int main() {
   cin >> R >> C;
   for (int r = 0; r < R; r++) {
      string tmp; cin >> tmp;
      for (int c = 0; c < C; c++) {
         grid[r][c] = tmp[c];
         state[r][c] = UNVISITED;
      }
   }
   parent.clear();
   ans = "No";

   for (int r = 0; r < R; r++)
      for (int c = 0; c < C; c++)
         if (state[r][c] == UNVISITED) {
            parent[ii(r, c)] = ii(-1, -1);
            dfs(r, c);
         }
   cout << ans << endl;
   return 0;
}
