/*
   greedy
   difficulty: easy
   date: 19/Aug/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N); for (int &a : A) cin >> a;

      sort(A.begin(), A.end());

      int prev = -1; bool has = false; int qtyOdd = 0;
      for (int a : A) {
         if (abs(a-prev) == 1) has = true;
         if (a%2 == 1) qtyOdd++;
         prev = a;
      }

      if (qtyOdd % 2 == 1 && !has)
         cout << "NO\n";
      else cout << "YES\n";
   }
	return 0;
}
