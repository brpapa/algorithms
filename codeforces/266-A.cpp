/*
   ad-hoc
   difficulty: easy
   problem: stones on the table
   date: 03/Dec/2019
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int N;
   cin >> N;

   int  count = 0;
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