/*
   greedy > bipartite matching
   difficulty: easy
   date: 15/Jan/2020 
   by @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   while (true) {
      int N, M; cin >> N >> M; 
      if (!N && !M) break;

      vector<int> diameters(N), heights(M);
      for (int &d : diameters) cin >> d;
      for (int &h : heights) cin >> h;

      sort(diameters.begin(), diameters.end());
      sort(heights.begin(), heights.end());

      int ans = 0, n, m;
      for (m = 0, n = 0; m < M && n < N; m++)
         if (diameters[n] <= heights[m]) {
            ans += heights[m];
            n++;
         }
      if (n == N)
         cout << ans << endl;
      else cout << "Loowater is doomed!" << endl;
   }
   return 0;
}
