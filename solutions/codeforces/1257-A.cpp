/*
   greedy
   difficulty: easy
   date: 23/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N, x, a, b; cin >> N >> x >> a >> b;
      cout << min(abs(a-b) + x, N-1) << endl;
   }
   return 0;
}
