/*
   math > ad-hoc
   difficulty: easy
   date: 09/Jun/2020
   problem: check if the number of divisors of n is odd
   hint: check if n is a perfect square
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   while (true) {
      unsigned int n; cin >> n; if (n == 0) break;
      int sn = (int)sqrt(n);
      if (n == sn*sn) cout << "yes" << endl;
      else cout << "no" << endl;
   }
	return 0;
}
