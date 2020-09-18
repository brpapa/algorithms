/*
   brute force > iterative
   difficulty: easy
   date: 09/May/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int C, N;
   while (cin >> C >> N) {
      vector<int> olives(2*C, 0);
      for (int n = 0; n < N; n++) {
         int c; cin >> c; olives[c] = olives[c+C] = 1;
      }

      vector<int> acc(2*C); acc[0] = olives[0];
      for (int i = 1; i < 2*C; i++) acc[i] = olives[i] + acc[i-1];

      char ans = 'N';
      for (int b = 0; b < C/N && ans == 'N'; b++) {
         bool flag = true;
         for (int l = b, r; l <= C; l = r) {
            r = l + (C/N);
            int rangeSum = acc[r] - acc[l]; // soma em [l+1 .. r]
            if (rangeSum != 1) flag = false;
         }
         if (flag) ans = 'S';
      }
      cout << ans << endl;
   }
   return 0;
}
