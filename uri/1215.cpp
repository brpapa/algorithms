/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   set<string> words;
   string s;
   while (getline(cin, s)) {
      string word = "";
      for (char c : s) {
         c = tolower(c);

         if (c >= 'a' && c <= 'z') {
            word += string(1, c);
         }
         else {
            if (word != "") words.insert(word);
            word = "";
         }
      }
      if (word != "") words.insert(word);
   }
   for (string word : words) cout << word << endl;
   return 0;
}