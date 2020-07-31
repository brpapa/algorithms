/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T >> ws;
   while (T--) {
      map<string, double> trees;
      double total = 0;

      string s;
      while (getline(cin, s) && s != "") {
         total++;
         if (!trees[s]) trees[s] = 1;
         else trees[s]++;
      }

      for (auto tree : trees)
         printf("%s %.4f\n", tree.first.c_str(), tree.second/total*100);
      if (T > 0) cout << endl;
   }   
   return 0;
}
