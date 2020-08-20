/*
   graphs > specials > bipartite > max cardinality bipartite matching
   difficulty: medium
   date: 17/Aug/2020
   problem: max number of preys that can hide safely from an predator attack
   hint: consider a bipartite graph with edges that connect a gopher (prey) to an reachable hole
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list; int V, LV;

vector<int> match; // match[r]: vértice l já combinado com r
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


int main() {
   int N, M, sec, vel;
   while (cin >> N >> M >> sec >> vel) {
      V = N+M; LV = N; adj_list.assign(V, vector<int>());

      // [0, N-1]: gophers
      // [N, N+M-1]: holes

      vector<pair<double,double>> gophers(N);
      for (int n = 0; n < N; n++)
         cin >> gophers[n].first >> gophers[n].second;

      for (int m = 0; m < M; m++) {
         pair<double,double> hole; cin >> hole.first >> hole.second;

         for (int n = 0; n < N; n++) {
            double dx = hole.first - gophers[n].first;
            double dy = hole.second - gophers[n].second;
            double dist = sqrt(dx*dx + dy*dy);
            double max_dist = (double)sec*vel;

            if (dist <= max_dist) // gopher n reach hole N+m?
               adj_list[n].push_back(N+m);
         }
      }

      cout << (N-mcbm()) << endl;
   }
}