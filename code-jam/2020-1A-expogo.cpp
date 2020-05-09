// TODO: implementar ideia de analysis > test case 3 em https://codingcompetitions.withgoogle.com/codejam/round/000000000019fef2/00000000002d5b62

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
map<ii, ii> parent;

bool hasSolution;

int tr, tc;
void dfs(int r, int c, int lvl) {
   if (hasSolution) return;

   printf("%2d %2d\n", r, c);

   int jump = (int)pow(2, lvl);
   // if (abs(r-tr) > jump || abs(c-tc) > jump) return;
   if (lvl > 1) return;

   if (r == tr && c == tc) {
      hasSolution = true;
      ii node = ii(r, c);
      while (node != ii(0, 0)) {
         printf("%2d %2d\n", node.first, node.second);
         node = parent[node];
      }
   }

   int dr[4] = {0, 0, jump, jump};
   int dc[4] = {jump, -jump, 0, 0};

   for (int d = 0; d < 4; d++) {
      int nr = r+dr[d];
      int nc = c+dc[d];

      parent[ii(nr, nc)] = ii(r, c);
      dfs(nr, nc, lvl+1);
   }
}

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      cin >> tr >> tc;

      cout << "Case " << (t++) << ": ";
      hasSolution = false;
      dfs(0, 0, 0);

      if (!hasSolution) cout << "IMPOSSIBLE" << endl;
   }   
   return 0;
}
