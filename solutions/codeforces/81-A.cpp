/*
   ad-hoc > implementation
   difficulty: easy
   date: 09/Mar/2020 
   by: @brpapa
*/
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;

void rec(char c) {
   s.pop();
   if (!s.empty()) rec(s.top());
   cout << c;
}

int main() {
   string str;
   cin >> str;

   for (char c : str) {
      if (!s.empty() && c == s.top()) s.pop();
      else s.push(c);
   }

   rec(s.top()); cout << endl;
   return 0;
}
