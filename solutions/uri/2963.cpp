/*
   ad-hoc
   difficulty: easy
   date: 14/Sep/2019 
   by: @brpapa
*/
#include <iostream>
using namespace std;

int main() {
   int N;
   cin >> N;

   int vCarlos, v;
   cin >> vCarlos;

   bool win = true;
   while (--N) {
      cin >> v;
      if (v > vCarlos)
         win = false;
   }
   cout << (win ? "S" : "N") << endl;
   return 0;
}