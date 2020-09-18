/*
   math > ad-hoc
   difficulty: easy
   date: 07/May/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   double x, y;
   while (cin >> x >> y) {
      double t = x;
      while (t/x - t/y < 1) t += x;
      cout << t/x << endl;
   }
   return 0;
}
