/*
   graphs > specials > bipartite > max cardinality bipartite matching
   difficulty: medium
   date: 19/Aug/2020
   hint: binary search on answer + MCBM
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list; int V, LV;
vector<pair<int,int>> reds, blues;
int K;

vector<int> match; // match[r] = vértice l já combinado com r
vector<bool> seen;

/* O(E) - returns 1 if an augmenting path is found */
int has_aug(int l) {
  if (seen[l]) return 0;
  seen[l] = true;

  for (int r : adj_list[l]) {
      if (match[r] == -1 || has_aug(match[r])) {
         match[r] = l;
         return 1;
      } 
  }
  return 0;
}

/* O(V*E) - return the max qty of matchings */
int mcbm() {
   int ans = 0;
   match.assign(V, -1);
   for (int l = 0; l < LV; l++) {
      seen.assign(LV, false);
      ans += has_aug(l);
   }
  return ans;
}

// com correntes de comprimento ans, há pelo menos K cercas?
bool can(int ans) {
   adj_list.assign(V, vector<int>());
   LV = reds.size();
   for (int i = 0; i < reds.size(); i++)
      for (int j = 0; j < blues.size(); j++) {
         int dx = reds[i].first - blues[j].first;
         int dy = reds[i].second - blues[j].second;
         if (sqrt(dx*dx + dy*dy) <= (double)ans)
            adj_list[i].push_back(LV+j);
      }
   return mcbm() >= K;
}

int main() {
   int T; cin >> T;
   while (T--) {
      cin >> V >> K;
      reds.clear(); blues.clear();
      for (int u = 0; u < V; u++) {
         int x,y; cin >> x >> y;
         string color; cin >> color;
         if (color == "red") reds.push_back({x,y});
         else blues.push_back({x,y});
      }

      int low = 1, high = 2002;
      int ans = -1;
      while (low <= high) {
         int mid = (low+high)/2;
         if (can(mid)) ans = mid, high = mid-1;
         else low = mid+1;
      }

      if (ans == -1) cout << "Impossible\n";
      else cout << ans << endl;
   }
   return 0;
}
