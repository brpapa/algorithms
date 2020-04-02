/*
   ad-hoc
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define MAX 300

string in2pos(string in) {
   stack<char> pilha;
   string str;
   for (int i = 0; i < in.size(); i++) {
      if (isalnum(in[i])) {
         str += in[i];
      }
      else if (in[i] == '(') {
         pilha.push(in[i]);
      }
      else if (in[i] == ')') {
         while (!pilha.empty() && pilha.top() != '(') {
            str += pilha.top();
            pilha.pop();
         }
         pilha.pop(); //remove '('
      }
      else {
         if (in[i] == '^')
            while (!pilha.empty() && pilha.top() != '(' && pilha.top() != '+' && pilha.top() != '-' && pilha.top() != '*' && pilha.top() != '/') {
               str += pilha.top();
               pilha.pop();
            }

         else if (in[i] == '*' || in[i] == '/')
            while (!pilha.empty() && pilha.top() != '(' && pilha.top() != '+' && pilha.top() != '-') {
               str += pilha.top();
               pilha.pop();
            }

         else if (in[i] == '+' || in[i] == '-')
            while (!pilha.empty() && pilha.top() != '(') {
               str += pilha.top();
               pilha.pop();
            }

         pilha.push(in[i]);
      }
   }
   while (!pilha.empty()) {
      str += pilha.top();
      pilha.pop();
   }
   return str;
}

int main() {
   int n;
   string in;

   cin >> n;
   while (n--) {
      cin >> in;
      cout << in2pos(in) << endl;
   }
   return 0;
}