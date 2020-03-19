/*
   math > ad-hoc
   difficulty: easy
   date: 17/Feb/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int s, d; cin >> s >> d;

      int a = s+d;
      int b = s-d;

      if (a < 0 || b < 0 || a%2 || b%2)
         cout << "impossible" << endl;
      else
         cout << a/2 << " " << b/2 << endl;

   }
   return 0;
}