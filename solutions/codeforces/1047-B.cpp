/*
   geometry
   difficulty: easy
   date: 27/Jun/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int N; cin >> N;
   int ans = 0;
   while (N--) {
      int x, y; cin >> x >> y;
      ans = max(ans, x+y);
   }
   cout << ans << endl;
}
