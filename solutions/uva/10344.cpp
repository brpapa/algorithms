/*
   brute force > recursive backtracking
   difficulty: easy
   date: 19/Mar/2020
   problem: check if some arithmetic expression of 5 given numbers will result in 23
   hint: check all combination of operators for each permutation of the given numbers
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[5];

bool bt(int acc, int i) {
   // valor total acc, operando-o com a[i]

   if (i == 5) return acc == 23;
   return bt(acc+a[i], i+1) || bt(acc-a[i], i+1) || bt(acc*a[i], i+1);
}

int main() {
   while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] && (a[0] || a[1] || a[2] || a[3] || a[4])) {
      bool ok = false;

      sort(a, a+5);
      do {
         if (ok = (ok || bt(a[0], 1))) break;
      } while (next_permutation(a, a+5));

      cout << (ok? "Possible" : "Impossible") << endl;
   }
   return 0;
}
