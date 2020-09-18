/*
   math > ad-hoc
   difficulty: easy
   date: 08/Jun/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   ll a, b, x, y; cin >> a >> b >> x >> y;

   for (int i = 2; i*i <= max(x, y); i++) 
      while (x % i == 0 && y % i == 0)
         x /= i, y /= i;

   if (a < x || b < y) cout << "0 0" << endl;
   else {
      int i = min(a/x, b/y);
      cout << i*x << " " << i*y << endl;
   }
   return 0;
}
