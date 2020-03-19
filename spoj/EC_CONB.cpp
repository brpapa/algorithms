/*
   ad-hoc
   difficulty: easy
   date: 21/Feb/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int a; cin >> a;
      if (a%2) {
         cout << a << endl;
         continue;
      }

      vector<bool> bits;
      bool mostRight1Found = false;
      for (int b = 31; b >= 0; b--) {
         if (mostRight1Found)
            bits.push_back(a & (1 << b));
         else if (a & (1 << b)) {
            mostRight1Found = true;
            bits.push_back(1);
         }
      }

      int ans = 0;
      for (int b = 0; b < bits.size(); b++)
         if (bits[b])
            ans |= (1 << b);
      cout << ans << endl;
   }
   return 0;
}