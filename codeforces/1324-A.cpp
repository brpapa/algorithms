/*
   math > ad-hoc > finding pattern
   difficulty: easy
   date: 12/Mar/2020 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N; 
      vector<int> A(N); for (int &a : A) cin >> a;

      bool ok = true;
      for (int n = 0; n+1 < N && ok; n++)
         if (abs(A[n]-A[n+1]) % 2 == 1)
            ok = false;

      if (ok) cout << "YES" << endl;
      else cout << "NO" << endl;
   }

   return 0;
}