/*
   ad-hoc
   difficulty: none
   problem: hours and minutes
   date: none
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int a;
   while (cin >> a)
      printf("%c\n", (a % 6 == 0) ? 'Y' : 'N');
   return 0;
}