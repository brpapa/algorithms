/*
   ad-hoc > implementation
   difficulty: easy
   date: 26/Dec/2019 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, M;
   cin >> N >> M;

   vector<int> p(N);
   for (int &i : p)
      cin >> i;

   int l, r, x;
   while (M--) {
      cin >> l >> r >> x;

      int qtyLess = 0;
      for (int i = l - 1; i < r; i++)
         if (p[i] < p[x - 1])
            qtyLess++;

      cout << (l - 1 + qtyLess == x - 1 ? "Yes" : "No") << endl;
   }
   return 0;
}