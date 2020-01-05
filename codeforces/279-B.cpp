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
   int currSum = 0; // do intervalo [l .. r)

   for (int l = 0; r < minNeeded.size(); l++) {
      if (l > 0)
         currSum -= minNeeded[l - 1];

      while (currSum <= T && r < minNeeded.size()) {
         currSum += minNeeded[r++];
      }
      if (currSum > T)
         currSum -= minNeeded[--r];

      // cout << l << " " << r << " " << currSum << endl;
      ans = max(ans, r - l);
   }
   cout << ans << endl;
   return 0;
}