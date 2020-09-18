/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   string text; getline(cin, text);
   int N; cin >> N;
   while (N--) {
      string s; cin >> s;

      int l = 0, f;
      bool found = false;

      while ((f = text.find(s, l)) != string::npos) {
         l = f+1;

         // ignora, se a substring text[f : f+s.size()-1] não é uma palavra completa
         if (text[f+s.size()] != ' ' && f+s.size() != text.size()) continue; 
         if (text[f-1] != ' ' && f != 0) continue; 

         cout << (found? " ": "") << f;
         found = true;
      }
      cout << (!found?"-1": "") << endl;
   }
   return 0;
}
