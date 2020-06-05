/*
   graphs > specials > tree
   difficulty: medium
   date: 04/Mar/2020
   problem: infix to postfix conversion
   hint: see that the given expression is the in-order traversal in a binary tree, then print post-order traversal recursively without building the tree
   by: @brnpapa
*/
#include <iostream>
using namespace std;

/*
(a+(b*c))

      +
    /   \
   a     *
       /   \
      b     c
*/

bool isOperator(char c) {
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string exp;
string rpn(int l, int r) {
   // substring [l .. r] de exp

   if (l == r) return string(1, exp[l]);

   int brackets = 0;
   for (int k = l; k <= r; k++) {
      if (exp[k] == '(') brackets++;
      if (exp[k] == ')') brackets--;

      if (brackets == 0 && isOperator(exp[k]))
         return rpn(l, k-1) + rpn(k+1, r) + exp[k];
   }

   if (exp[l] == '(' && exp[r] == ')')
      return rpn(l+1, r-1);
}

int main() {
   int T; cin >> T;
   while (T--) {
      cin >> exp;
      cout << rpn(0, exp.size()-1) << endl;
   }   
   return 0;
}