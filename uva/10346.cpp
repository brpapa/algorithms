/*
   math > ad-hoc
   difficulty: easy
   date: 14/Feb/2020 
   by @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int N, K;
   while (cin >> N >> K) {
      int toSmoke = N, smoked = 0, butts = 0;

      while (toSmoke > 0) {
         smoked += toSmoke;
         butts += toSmoke;

         toSmoke = butts/K;
         butts %= K;
      }
      cout << smoked << endl;
   }
   return 0;
}
