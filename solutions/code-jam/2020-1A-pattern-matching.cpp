/*
   greedy
   difficulty: medium
   date: 11/Apr/2020
   solution: note that only the prefix and suffix constraints matter
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      int N; cin >> N;

      string cprefix = "", csuffix = ""; // constraints do preffix e suffix
      string mid = "";
      bool ok = true;

      while (N--) {
         string s; cin >> s;
         int ffo = s.find_first_of("*");
         int flo = s.find_last_of("*");

         // substring de s antes do primeiro "*"
         string b = s.substr(0, ffo);
         if (b.find(cprefix) == 0 || cprefix.find(b) == 0) {
            if (b.size() > cprefix.size()) cprefix = b;
         }
         else ok = false;

         // substring do meio
         for (int i = ffo+1; i < flo; i++)
            if (s[i] != '*')
               mid += s[i];

         // substring de s depois do último "*"
         string e = s.substr(flo+1); 
         reverse(e.begin(), e.end());
         if (e.find(csuffix) == 0 || csuffix.find(e) == 0) {
            if (e.size() > csuffix.size()) csuffix = e;
         }
         else ok = false;
      }
      reverse(csuffix.begin(), csuffix.end());
      string ans = cprefix+mid+csuffix;

      printf("Case #%d: ", t++);
      cout << (ok? ans:"*") << endl;
   }
   return 0;
}