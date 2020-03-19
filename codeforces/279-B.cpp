/*
   techniques > two pointers
   difficulty: medium
   date: 29/Dec/2019
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, T;
   cin >> N >> T;

   vector<int> mn(N); // min needed
   for (int &min : mn)
      cin >> min;

   int ans = 0, r = 0;
   int t = 0; // soma atual do intervalo [l .. r)

   for (int l = 0; r < N; l++) {
      if (l > 0) t -= mn[l - 1];

      while (t <= T && r < N) {
         t += mn[r++];
      }
      if (t > T) t -= mn[--r];

      // cout << l << " " << r << " " << t << endl;
      ans = max(ans, r - l);
   }
   cout << ans << endl;
   return 0;
}