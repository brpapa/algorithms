/*
   ad-hoc
   difficulty: easy
   date: 14/Sep/2019 
   by @brnpapa
*/
#include <cmath>
#include <iostream>
using namespace std;

int main() {
   int V, N;
   cin >> V >> N;

   cout << (int)ceil((double)V * N * 1 / 10);
   for (int i = 2; i <= 9; i++) {
      cout << " " << (int)ceil((double)V * N * i / 10);
   }
   cout << endl;
   return 0;
}