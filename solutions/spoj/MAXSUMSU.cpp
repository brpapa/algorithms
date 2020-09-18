/*
   dynamic programming > max 1D range sum > kadane
   difficulty: easy
   date: 10/Jan/2020 
   by: @brpapa
*/
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int N;
vector<int> a;

int kadaneBU(int l, int r) {
   int maxTotal = -INF, maxCurr = 0;

   for (int i = l; i < r; i++) {
      maxCurr = max(maxCurr + a[i], a[i]);
      maxTotal = max(maxTotal, maxCurr);
   }
   return maxTotal;
}

int main() {
   int T;
   cin >> T;
   while (T--) {
      cin >> N;
      a.resize(N);
      for (int &aa : a)
         cin >> aa;

      cout << kadaneBU(0, N) << endl;
   }
   return 0;
}