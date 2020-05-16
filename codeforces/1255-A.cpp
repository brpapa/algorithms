/*
   greedy > restrict coin change
   difficulty: easy
   date: 25/Nov/2019 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> buttons = {5, 2, 1};
   
   int T;
   cin >> T;

   int a, b;
   while (T--) {
      cin >> a >> b;
      int diff = abs(a - b);

      int ans = 0;
      for (int btn : buttons) {
         ans += diff/btn;
         diff %= btn;
      }
      cout << ans << endl;
   }
   return 0;
}