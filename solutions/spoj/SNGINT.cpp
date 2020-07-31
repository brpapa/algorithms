/*
   greedy
   difficulty: easy
   date: 22/Apr/2020
   problem: given an integer n, find the smallest positive integer m > 0 such that the product of digits of m equals n
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n == 0) { cout << 10 << endl; continue; }
      if (n == 1) { cout << 1 << endl;  continue; }

      vector<int> revAns;
      for (int d = 9; d >= 2 && n > 1; d--)
         while (n%d == 0) revAns.push_back(d), n /= d;

      if (n > 1) cout << -1;
      else for (int i = revAns.size()-1; i >= 0; i--) cout << revAns[i];
      cout << endl;
   }
   return 0;
}