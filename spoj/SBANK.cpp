/*
   ad-hoc
   difficulty: easy
   problem: sorting bank accounts
   date: 02/Mar/2020
   author: @brnpapa
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N >> ws;

      map<string, int> m;
      while (N--) {
         string str; getline(cin, str);
         if (str.size() == 32) str.erase(str.end()-1);

         if (m[str]) m[str]++;
         else m[str] = 1;
      }

      for (auto i : m) {
         cout << i.first << " " << i.second << endl;
      }
      if (T > 0) cout << endl;
   }
   return 0;
}