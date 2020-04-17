/*
   math > game theory > minimax > optimized
   difficulty: hard
   date: 28/Mar/2020
   problem: multiplication game
   solution: note that if Stan always multiply by 9 and Ollie by 2, it's still an optimal solution
   by: @brnpapa
*/
#include <iostream>
using namespace std;
const int STAN = 0, OLLIE = 1;

int N;
int f(int p, int n) {
   // jogador atual p, inteiro n

   if (n >= N) return !p; // p é perdedor

   if (p == STAN) return f(!p, n*9); // max
   else           return f(!p, n*2); // min
}

int main() {
   while (cin >> N) {
      cout << (f(STAN, 1) == STAN? "Stan" : "Ollie") << " wins.\n";
   }
   return 0;
}
