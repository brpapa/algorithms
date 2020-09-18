/*
   ad-hoc
   difficulty: easy
   date: 09/Nov/2019 
   by: @brpapa
*/
#include <iostream>
using namespace std;

int main() {
   int N, X;
   cin >> N >> X;

   int maxLocal = 1, maxGlobal = 1; // tamanho da sequência contígua

   int hPrev, hCurr;
   cin >> hPrev;
   while (--N) {
      cin >> hCurr;

      if (hCurr - hPrev <= X)
         maxLocal++;
      else maxLocal = 1;

      maxGlobal = max(maxGlobal, maxLocal);
      hPrev = hCurr;
   }
   cout << maxGlobal << endl;
   return 0;
}