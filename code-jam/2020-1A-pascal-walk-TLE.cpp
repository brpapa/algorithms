/*
   graphs > traversal
   difficulty: medium
   date: 11/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_S 505

int C[MAX_S][MAX_S];
bool foundSolution;

map<pair<int, int>, bool> visited;
map<pair<int,int>, pair<int,int>> parent;

void walk(int r, int k, int n) {
   // posicao atual (r, k), soma N-n atual

   if (foundSolution) return;

   if (n == 0) {
      foundSolution = true;
      vector<pair<int, int>> ans;

      pair<int, int> p = parent[make_pair(r, k)];
      while (p != make_pair(-1, -1)) {
         ans.push_back(p);
         p = parent[p];
      }

      reverse(ans.begin(), ans.end());
      for (auto a : ans)
         cout << a.first << " " << a.second << endl;
   }

   if (r < 1 || k < 1 || k > r || n < 0) return;
   visited[make_pair(r, k)] = true;

   int dr[6] = {-1, -1, 0, 0, 1, 1};
   int dk[6] = {-1, 0, -1, 1, 0, 1};
   for (int d = 0; d < 6; d++) {
      int nr = r + dr[d];
      int nk = k + dk[d];

      if (!visited[make_pair(nr, nk)]) {
         parent[make_pair(nr, nk)] = make_pair(r, k);
         walk(nr, nk, n-C[r][k]);
      }
   }
}

int main() {
   for (int r = 1; r < MAX_S; r++) {
      C[r][1] = 1;
      C[r][r] = 1;
      for (int k = 2; k < r; k++)
         C[r][k] = C[r-1][k-1] + C[r-1][k];
   }

   int T, t = 1; cin >> T;
   while (T--) {
      int N; cin >> N;
      foundSolution = false;
      parent.clear();
      visited.clear();

      printf("Case #%d:\n", t++);
      parent[make_pair(1, 1)] = make_pair(-1, -1);
      walk(1, 1, N);
   }
   return 0;
}