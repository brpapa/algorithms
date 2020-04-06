/*
   greedy
   difficulty: easy
   date: 03/Apr/2020
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      string s; cin >> s;

      string ans;
      int d = 0; // depth atual (qte de parenteses que precisam ser fechados)

      for (char c : s) {
         int nd = c-'0';
         while (nd > d) ++d, ans += "(";
         while (nd < d) --d, ans += ")";
         ans += c;
      }
      while (d > 0) --d, ans += ")";

      printf("Case #%d: %s\n", t++, ans.c_str());
   }
   return 0;
}