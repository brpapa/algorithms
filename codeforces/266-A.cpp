/*
   ad-hoc > implementation
   difficulty: easy
   date: 03/Dec/2019
   problem: none
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int N;
   cin >> N;

   int count = 0;
   char curr, prev;

   cin >> prev;
   while (--N) {
      cin >> curr;
      if (curr == prev)
         count++;
      prev = curr;
   }
   cout << count << endl;
   return 0;
}