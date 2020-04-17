/*
   math > ad-hoc
   difficulty: easy
   date: 14/Feb/2020 
   by: @brnpapa
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int R, N, D, T = 1;
   while (true) {
      cin >> R >> N; if (!R && !N) break;

      // (D+1)*N >= R
      D = (int)ceil((double)R/N - 1);

      cout << "Case " << (T++) << ": ";
      if (D > 26) cout << "impossible" << endl;
      else cout << D << endl;
   }
   return 0;
}
