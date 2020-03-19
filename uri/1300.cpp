/*
   ad-hoc
   difficulty: none
   date: none
   problem: none
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int a;
   while (cin >> a)
      printf("%c\n", (a % 6 == 0) ? 'Y' : 'N');
   return 0;
}