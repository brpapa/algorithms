/*
   ad-hoc
   difficulty: easy
   date: 08/May/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, M;
   while (cin >> N >> M) {
      int ans = 0, g;
      while (N--) {
         int mn = 101;
         for (int m = 0; m < M; m++)
            cin >> g, mn = min(mn, g);

         ans += mn > 0;
      }
      cout << ans << endl;
   }
   return 0;
}