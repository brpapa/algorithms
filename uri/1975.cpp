/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int P, A, R; 
   while (cin >> P >> A >> R >> ws && (P || A || R)) {
      set<string> p;
      while (P--) {
         string s; getline(cin, s);
         p.insert(s);
      }

      map<string, int> as;
      int mx = -1;
      while (A--) {
         string sa; getline(cin, sa);

         set<string> tmp;
         for (int r = 0; r < R; r++) {
            string pa; getline(cin, pa);
            if (p.count(pa)) tmp.insert(pa);
         }

         as[sa] = as[sa] + tmp.size();
         mx = max(mx, as[sa]);
      }

      vector<string> ans;

      for (auto a : as) { 
         string sa = a.first;
         int count = a.second;

         if (count == mx) ans.push_back(sa);
      }
      
      for (int i = 0; i+1 < ans.size(); i++) cout << ans[i] << ", ";
      cout << ans.back() << endl;
   }

   return 0;
}
