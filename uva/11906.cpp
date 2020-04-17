/*
   graphs > traversal
   difficulty: medium
   date: 28/Feb/2020 
   solution: consider grid as an implicit graph and walk through it avoiding redundant positions (nr, nc)
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
#define mp make_pair
#define UNVISITED 0
#define VISITING 1
#define WATER 2
#define EVEN 3
#define ODD 4

int R, C, M, N;
int grid[110][110];

set<pair<int, int>> d; // dr, dc
void walk(int r, int c) {
   if (grid[r][c] != UNVISITED) return;
   
   grid[r][c] = VISITING;
   int countAdjReachable = 0;

   // para cada distinto adjacente de grid[r][c]
   for (pair<int, int> n : d) {
      int nr = r+n.first, nc = c+n.second;
      if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != WATER) {
         countAdjReachable++;
         walk(nr, nc);
      }
   }

   if (countAdjReachable%2) grid[r][c] = ODD;
   else grid[r][c] = EVEN;
}

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      memset(grid, UNVISITED, sizeof grid);

      cin >> R >> C >> M >> N;
      int W; cin >> W;
      while (W--) {
         int r, c; cin >> r >> c;
         grid[r][c] = WATER;
      }

      d.clear();
      // descarta possíveis redundâncias
      d.insert({ 
         mp(M, N), mp(-M, N), mp(M, -N), mp(-M, -N),
         mp(N, M), mp(N, -M), mp(-N, M), mp(-N, -M) 
      }); 

      walk(0, 0);

      int countEven = 0, countOdd = 0;
      for (int r = 0; r < R; r++)
         for (int c = 0; c < C; c++) {
            if (grid[r][c] == EVEN) countEven++;
            if (grid[r][c] == ODD) countOdd++;
         }
      cout << "Case " << t << ": " << countEven << " " << countOdd << endl;
   }   
   return 0;
}
