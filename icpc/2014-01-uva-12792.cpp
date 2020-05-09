/*
   brute force > iterative
   difficulty: medium
   date: 08/May/2020
   problem: simulation
   solution: note that if you 'watch' a unique card, the full deck will become sorted as soon as this card reaches its original position
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   while (cin >> N) {
      int ans = 1, p1 = 2; // atual posição do número 1
      while (p1 != 1) {
         if (p1 <= N/2) p1 *= 2;
         else           p1 = p1*2-N-1;
         ans++;
      }
      cout << ans << endl;
   }
   return 0;
}
