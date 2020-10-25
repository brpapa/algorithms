/*
   miscellaneous > bitmask
   difficulty: easy
   date: 24/Oct/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
   int N; cin >> N;
   while (N--) {
      ull l, r; cin >> l >> r;

      for (ull i = 0; i < 64 && (l | (1ull << i)) <= r; i++)
         l = l | (1ull << i);
      cout << l << endl;
   }
	return 0;
}
