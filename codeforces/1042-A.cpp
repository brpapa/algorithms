/*
   math > ad-hoc
   difficulty: easy
   date: 30/Mar/2020
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
#define INF (1 << 30)
using namespace std;

int main() {
   int N, m; cin >> N >> m;
   vector<int> A(N); for (int &a : A) cin >> a;

   int mx = -INF; for (int a : A) mx = max(mx, a);
   int diff = 0;  for (int a : A) diff += mx-a;

   int nm = max(m-diff, 0);

   cout << (int)ceil((double)nm/N) + mx << " " << m+mx << endl;
   return 0;
}
