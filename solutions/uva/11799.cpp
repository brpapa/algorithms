/*
   ad-hoc
   difficulty: easy
   date: 17/Feb/2020 
   by: @brnpapa
*/
#include <iostream>
#define INF (int)0x7f7f7f7f
using namespace std;

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      int N; cin >> N;
      int ans = -INF;
      while (N--) {
         int c; cin >> c;
         ans = max(ans, c);
      }
      printf("Case %d: %d\n", t, ans);
   }
   return 0;
}