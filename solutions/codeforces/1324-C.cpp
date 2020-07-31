/*
   greedy
   difficulty: easy
   date: 15/Mar/2020 
   hint: note that it's unnecessary jump to the left, so to minimize d, just jump between the nearest 'R' cells
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#define INF (1 << 30)
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      string str; cin >> str;

      vector<int> posR = {0};
      for (int i = 0; i < str.size(); i++)
         if (str[i] == 'R')
            posR.push_back(i+1);
      posR.push_back(str.size()+1);

      int ans = -INF;
      for (int i = 0; i+1 < posR.size(); i++)
         ans = max(ans, posR[i+1]-posR[i]);
      cout << ans << endl;
   }
   return 0;
}