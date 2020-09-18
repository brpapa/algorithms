/*
   greedy
   difficulty: easy
   date: 23/Apr/2020
   problem: compute the maximum number of activities (each with start and end times) that you can do without overlapping them (one at a time)
   hint: sort the activites by increasing end time
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // start, end

// p1 < p2
bool cmp(const ii p1, const ii p2) {
   return p1.second < p2.second;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<ii> time(N); for (ii &t : time) cin >> t.first >> t.second;

      sort(time.begin(), time.end(), cmp);

      int ans = 1; ii curr = time[0];
      for (int i = 1; i < N; i++)
         if (time[i].first >= curr.second)
            ans++, curr = time[i];

      cout << ans << endl;
   }
   return 0;
}