/*
   greedy > loading balance
   difficulty: easy
   problem: the bus driver problem
   date: 16/Jan/2020
   author: @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   while (true) {
      int N, D, R; cin >> N >> D >> R;
      if (!N && !D && !R) break;

      vector<int> morning(N), evening(N);
      for (int &m : morning) cin >> m;
      for (int &e : evening) cin >> e;
      sort(morning.begin(), morning.end());
      sort(evening.rbegin(), evening.rend());

      int ans = 0;
      for (int i = 0; i < N; i++)
         ans += max(0, (morning[i]+evening[i]-D)*R);
      cout << ans << endl;
   }
   return 0;
}
