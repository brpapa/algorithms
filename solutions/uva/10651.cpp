/*
   dynamic programming
   difficulty: medium
   date: 08/Feb/2020 
   hint: use bitmasks
   by: @brpapa
*/
#include <iostream>
#include <cstring>
#define isOn(S, i) (S & (1 << (i)))
#define INF 13
using namespace std;

int memo[1 << 13];
int dp(int mask) {
   // mask: conjunto atual

   int &ans = memo[mask];
   if (ans != -1) return ans;
   
   ans = INF;

   for (int i = 0; i <= 9; i++)
      if (!isOn(mask, i) && isOn(mask, i+1) && isOn(mask, i+2))
         ans = min(ans, dp(mask & ~(1 << (i+1)) & ~(1 << (i+2)) | (1 << i)));

   for (int i = 11; i >= 2; i--)
      if (!isOn(mask, i) && isOn(mask, i-1) && isOn(mask, i-2))
         ans = min(ans, dp(mask & ~(1 << (i-1)) & ~(1 << (i-2)) | (1 << i)));

   return ans = (ans < INF)? ans : __builtin_popcount(mask);
}

int main() {
   int T; cin >> T;
   memset(memo, -1, sizeof memo);
   while (T--) {
      int mask = 0;
      for (int i = 0; i < 12; i++) {
         char c; cin >> c;
         if (c == 'o') mask |= (1 << i);
      }
      cout << dp(mask) << endl;
   }
   return 0;
}