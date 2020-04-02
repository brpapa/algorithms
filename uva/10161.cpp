/*
   math > ad-hoc > finding pattern
   difficulty: medium
   date: 15/Feb/2020 
   by @brnpapa
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   while (true) {
      int n; cin >> n; if (!n) break;

      int cs = (int)ceil(sqrt((double)n));
      int rs = (int)round(sqrt((double)n));

      int l, c;
      if (cs == rs) {
         l = cs;
         c = cs*cs-n+1;
      }
      else {
         c = cs;
         l = n-(cs-1)*(cs-1);
      }

      if (cs % 2) swap(l, c);
      cout << l << " " << c << endl;
   }
   return 0;
}
