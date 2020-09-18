/*
   ad-hoc > implementation
   difficulty: easy
   date: 26/Jun/2020
   problem: skyline
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> maxH(10001, 0);

   int l, h, r;
   int maxR = -1;
   while (cin >> l >> h >> r) {
      maxR = max(maxR, r);
      for (int i = l; i < r; i++)
         maxH[i] = max(maxH[i], h);
   }

   int prev = 0;
   for (int i = 0; i < maxR; i++) {
      int curr = maxH[i];
      if (curr != prev) cout << i << " " << curr << " ";

      prev = curr;
   }
   cout << maxR << " 0\n";
	return 0;
}
