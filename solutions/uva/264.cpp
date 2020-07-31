/*
   math > ad-hoc > sequences
   difficulty: medium
   date: 18/Feb/2020
   hint: use binary search on preprocessed f(x)=f(x-1)+x-1
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1  2  3  4   5   6  ...  x
1  2  4  7  11  16  ...  f(x)

f(x) = f(x-1)+x-1

f(10^4-1) > 10^7
*/

int main() {
   vector<int> f((int)1e4);
   f[0] = 1;
   for (int x = 1; x < (int)1e4; x++) f[x] = f[x-1]+x-1;

   int n;
   while (cin >> n) {
      int x = upper_bound(f.begin(), f.end(), n) - f.begin() - 1;

      int num = 1 + (n-f[x]);
      int den = x - (n-f[x]);

      if (x%2) swap(num, den);
      printf("TERM %d IS %d/%d\n", n, num, den);
   }
   return 0;
}