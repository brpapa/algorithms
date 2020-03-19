/*
   ad-hoc
   difficulty: easy
   date: 17/Feb/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
   int N; cin >> N;
   map<char, int> qty;

   while (N--) {
      char c; cin >> c;
      if (qty.count(c) == 0) qty[c] = 1;
      else qty[c]++;
   }

   int qty1 = min(qty['o'], min(qty['n'], qty['e']));
   qty['o'] -= qty1; qty['n'] -= qty1; qty['e'] -= qty1;

   int qty0 = min(min(qty['z'], qty['e']), min(qty['r'], qty['o']));

   for (int q = 0; q < qty1; q++) cout << 1 << " ";
   for (int q = 0; q < qty0; q++) cout << 0 << " ";
   cout << endl;

   return 0;
}