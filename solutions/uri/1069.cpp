/*
   ad-hoc
   difficulty: none
   date: none 
   by: @brpapa
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
   string str;
   stack<char> p;
   int n, quant;
   cin >> n;
   for (int i = 0; i < n; i++) {
      quant = 0;
      cin >> str;
      for (int i = 0; i < str.size(); i++) {
         if (str.at(i) == '<')
            p.push(str.at(i));
         if (str.at(i) == '>' && p.top() == '<')
            if (!p.empty()) {
               p.pop();
               quant++;
            }
      }
      cout << quant << endl;

      while (!p.empty())
         p.pop();
   }
   return 0;
}