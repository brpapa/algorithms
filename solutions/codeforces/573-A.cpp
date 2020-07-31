/*
   math > ad-hoc
   difficulty: medium
   date: 08/Jun/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

/*
   75*2 == 150*1 == 50*3
   100*3 == 150*2 != 250*n
*/

int main() {
   int N; cin >> N; vector<int> A(N);
   for (int &a : A) { 
      cin >> a;
      while (a % 2 == 0) a /= 2; 
      while (a % 3 == 0) a /= 3;
   }

   string ans = "Yes";

   int first = A[0];
   for (int a : A) if (a != first) ans = "No";

   cout << ans << endl;
	return 0;
}
