/*
   ad-hoc
   difficulty: easy
   date: 02/May/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      int x, y; cin >> x >> y;
      string m; cin >> m;

      vector<ii> path; 
      path.push_back(ii(x, y)); // time 0
      for (char c : m) {
         if (c == 'N') path.push_back(ii(path.back().first, path.back().second+1));
         if (c == 'E') path.push_back(ii(path.back().first+1, path.back().second));
         if (c == 'S') path.push_back(ii(path.back().first, path.back().second-1));
         if (c == 'W') path.push_back(ii(path.back().first-1, path.back().second));
      }

      int ans = -1;
      for (int i = 0; i < path.size() && ans == -1; i++)
         if (abs(path[i].first) + abs(path[i].second) <= i)
            ans = i;
      
      printf("Case #%d: ", t);
      if (ans == -1) cout << "IMPOSSIBLE"; else cout << ans;
      cout << endl;
   }
   return 0;
}
