/*
   ad-hoc
   difficulty: none
   date: none
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
   string str;
   stack<char> p;
   while (cin >> str) {
      bool ok = true;
      for (int i = 0; i < str.size(); i++) {
         if (str.at(i) == '(')
            p.push(str.at(i));
         else if (str.at(i) == ')') {
            if (!p.empty() && p.top() == '(')
               p.pop();
            else
               ok = false;
         }
      }
      printf("%s\n", (p.empty() && ok) ? "correct" : "incorrect");
      while (!p.empty())
         p.pop();
   }
   return 0;
}