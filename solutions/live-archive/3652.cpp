/*
   graphs > shortest path > single-source > weighted graph
   difficulty: hard
   date: 18/May/2020
   problem: dijkstra on a given implicit graph as a 2D grid
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define mp make_pair
const int INF = 1 << 30;
const int MAX = 1001;
const int DRY = 0;
const int WATERY = 1;

int grid[MAX][MAX];
int C, R;

int sd[MAX][MAX];
int dr[24] = {1,0,-1, 0,  1,-1, 1,-1,  2,0,-2, 0,  2,-2, 2,-2,1,-1, 1,-1,  2,-2, 2,-2};
int dc[24] = {0,1, 0,-1,  1, 1,-1,-1,  0,2, 0,-2,  1, 1,-1,-1,2, 2,-2,-2,  2, 2,-2,-2}; 
int wd[24] = {2,2, 2, 2,  3, 3, 3, 3,  5,5, 5, 5,  6, 6, 6, 6,6, 6, 6, 6,  7, 7, 7, 7};
int dijk(int sr, int sc, int tr, int tc) {
   for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) sd[r][c] = INF;

   priority_queue<pair<int, ii>> pq; // (-d, (r, c))
   pq.push(mp(0, mp(sr, sc)));
   sd[sr][sc] = 0;

   while (!pq.empty()) {
      int u_d = -pq.top().first;
      int r = pq.top().second.first;
      int c = pq.top().second.second;
      pq.pop();

      if (u_d > sd[r][c]) continue; // lazy deletion

      // para cada aresta (r,c) --wd[d]--> (nr,nc) válida
      for (int d = 0; d < 24; d++) {
         int nr = r + dr[d];
         int nc = c + dc[d];

         if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
         if (grid[nr][nc] == WATERY) continue;

         int &od = sd[nr][nc];
         int nd = sd[r][c] + wd[d];

         if (nd < od) {
            od = nd;
            pq.push(mp(-nd, mp(nr, nc)));
         }
      }
   }

   return sd[tr][tc];
}


int main() {
   while (cin >> C >> R && (C || R)) {
      int sc, sr; cin >> sc >> sr; sc--; sr--;
      int tc, tr; cin >> tc >> tr; tc--; tr--;
      memset(grid, DRY, sizeof grid);
      int W; cin >> W;
      while (W--) {
         int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2; c1--; r1--; c2--; r2--;
         for (int r = r1; r <= r2; r++) for (int c = c1; c <= c2; c++) grid[r][c] = WATERY;
      }

      int ans = dijk(sr, sc, tr, tc);
      if (ans == INF) cout << "impossible" << endl;
      else cout << ans << endl;
	}
	return 0;
}
