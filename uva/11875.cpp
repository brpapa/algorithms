/*
   math > ad-hoc
   difficulty: easy
   date: 14/Feb/2020 
   by: @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      int N; cin >> N;
      for (int n = 0; n < N; n++) {
         int a; cin >> a;
         if (n == (N-1)/2) cout << "Case " << t << ": " << a << endl;
      }
   }
   return 0;
}
