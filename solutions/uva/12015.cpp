/*
   ad-hoc
   difficulty: easy
   date: 17/Feb/2020 
   by: @brpapa
*/
#include <iostream>
#include <vector>
#define INF (int)0x7f7f7f7f
using namespace std;

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      string page;
      vector<string> ans;

      int r, rMax = -INF;
      for (int l = 0; l < 10; l++) {
         cin >> page >> r;
         if (r > rMax) {
            rMax = r;
            ans.clear(); ans.push_back(page);
         }
         else if (r == rMax) {
            ans.push_back(page);
         }
      }

      printf("Case #%d:\n", t);
      for (string a : ans) cout << a << endl;
   }
   return 0;
}
