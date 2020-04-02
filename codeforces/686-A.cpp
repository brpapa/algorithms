/*
   ad-hoc
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   long long int x, d;
   int n, cont = 0;
   char op;
   cin >> n >> x;
   for (int i = 0; i < n; i++) {
      cin >> op >> d;
      if (op == '+')
         x += d;
      else (x >= d)? (x -= d):(cont++);
   }
   cout << x << " " << cont << endl;
   return 0;
}  