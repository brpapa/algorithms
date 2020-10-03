/*
   greedy
   difficulty: medium
   date: 25/Sep/2020
   problem: length of the longest inc/dec (alternating) subsequence
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      
      int prev = 0, curr;
      int hi = 0;
      int lo = 0;

      for (int i = 0; i < n; i++) {
         cin >> curr;
         if (curr > prev) hi = lo+1;
         if (curr < prev) lo = hi+1;
         prev = curr;
      }
      cout << max(lo, hi) << endl;
   }
	return 0;
}
