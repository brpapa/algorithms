/*
   brute force > recursive backtracking
   difficulty: easy
   date: 14/Apr/2020
   problem: given an unweighted implicit graph, count the longest possible path
   solution: graph traversal + backtracking
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15;

const int BLOCKED = -1;
const int UNVISITED = 0;
const int VISITED = 1;

int board[MAX_N][MAX_N];
int maxQtyVisited;

void bfs(int r, int c, int qtyVisited) {
   maxQtyVisited = max(maxQtyVisited, qtyVisited);
   board[r][c] = VISITED;

   int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
   int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

   for (int d = 0; d < 8; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];

      if (nr >= 0 && nc >= 0 && board[nr][nc] == UNVISITED)
         bfs(nr, nc, qtyVisited+1);
   }
   board[r][c] = UNVISITED; // backtracking
}

int main() {
   int t = 1, N;
   while (cin >> N && N) {
      memset(board, BLOCKED, sizeof board);
      maxQtyVisited = 0;

      int ans = 0;
      for (int n = 0; n < N; n++) {
         int s, e; cin >> s >> e;
         for (int c = s; c < s+e; c++)
            board[n][c] = UNVISITED, ans++;
      }

      bfs(0, 0, 1);
      ans -= maxQtyVisited;
      printf("Case %d, %d %s can not be reached.\n", t++, ans, ans != 1? "squares":"square");
   }
   
   return 0;
}
