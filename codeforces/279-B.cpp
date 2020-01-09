/*
   searching > two pointers
   difficulty: medium
   problem: books
   date: 29/Dec/2019
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, T;
   cin >> N >> T;

   vector<int> minNeeded(N);
   for (int &min : minNeeded)
      cin >> min;

   int ans = 0, r = 0;
   int t = 0; // soma atual do intervalo [l .. r)

   for (int l = 0; r < N; l++) {
      if (l > 0)
         t -= minNeeded[l - 1];

      while (t <= T && r < N) {
         t += minNeeded[r++];
      }
      if (t > T)
         t -= minNeeded[--r];

      // cout << l << " " << r << " " << t << endl;
      ans = max(ans, r - l);
   }
   cout << ans << endl;
   return 0;
}