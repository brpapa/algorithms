/*
   data structures | stack
   problem: easy stack
   author: @brnpapa
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
   int t, op;
   long long int n;
   stack<long long int> p;

   scanf("%d", &t);
   while (t--) {
      scanf("%d", &op);
      if (op == 1) {
         scanf("%lli", &n);
         p.push(n);
      }
      else if (op == 2 && !p.empty()) {
         p.pop();
      }
      else if (op == 3) {
         if (!p.empty())
            printf("%lli\n", p.top());
         else
            printf("Empty!\n");
      }
   }
   return 0;
}