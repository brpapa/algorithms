/*
   math > ad-hoc > finding pattern
   difficulty: easy
   date: 30/Mar/2020
   by: @brnpapa
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int c, m, x; cin >> c >> m >> x;

      int nx = x+abs(c-m);
      int ncm = min(c, m);

      cout << (ncm <= nx? min(ncm, nx) : (2*ncm+nx)/3) << endl;
   }
   return 0;
}
