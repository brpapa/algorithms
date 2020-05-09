/*
   graphs > shortest path > single-source > unweighted graph
   difficulty: medium
   date: 08/May/2020
   solution: apply a BFS for each subset of letters possible (only 2^10) using bitmask
   by: @brnpapa
*/
#include <bits/stdc++.h>
#define INF (1 << 30)
#define UNVISITED 0
#define VISITED 1
using namespace std;
typedef pair<int, int> ii;

int N;
char grid[101][101];
int state[101][101];
int lvl[101][101];

int mask; // 0100 = 3a lowercase está habilitada, e 3a uppercase está desabilitada
bool check(char ch) {
   if (islower(ch)) return (mask & (1 << (ch-'a')));
   return !(mask & (1 << (ch-'A')));
}

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int bfs(int sr, int sc) {
   for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) state[r][c] = UNVISITED, lvl[r][c] = INF;
   queue<ii> q; if (check(grid[sr][sc])) q.push(ii(sr, sc));
   lvl[sr][sc] = 1;

   while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      state[r][c] = VISITED;

      // (r, c) -> (nr, nc)
      for (int d = 0; d < 4; d++) {
         int nr = r + dr[d];
         int nc = c + dc[d];
         if (nr < 0 || nr == N || nc < 0 || nc == N) continue;
         if (state[nr][nc] == VISITED)               continue;

         if (check(grid[nr][nc])) {
            lvl[nr][nc] = lvl[r][c] + 1;
            q.push(ii(nr, nc));
         }
      }
   }
   return lvl[N-1][N-1];
}

int main() {
   while (cin >> N) {
      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            cin >> grid[i][j];

      int ans = INF;
      for (mask = 0; mask < (1 << 10); mask++) // O(2^10)
         ans = min(ans, bfs(0, 0));
      cout << (ans == INF? -1 : ans) << endl;
   }
   return 0;
}
