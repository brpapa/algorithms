/*
   greedy > bipartite matching
   difficulty: easy
   date: 15/Jan/2020 
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, M; 
   while (cin >> N >> M && (N || M)) {
      vector<int> diameters(N), heights(M);
      for (int &d : diameters) cin >> d;
      for (int &h : heights) cin >> h;

      sort(diameters.begin(), diameters.end());
      sort(heights.begin(), heights.end());

      int ans = 0, n = 0;
      for (int m = 0; m < M && n < N; m++)
         if (diameters[n] <= heights[m])
            ans += heights[m], n++;

      if (n == N) cout << ans << endl;
      else cout << "Loowater is doomed!" << endl;
   }
   return 0;
}
