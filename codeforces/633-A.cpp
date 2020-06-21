/*
   brute force > iterative
   difficulty: easy
   date: 17/Jun/2020
   problem: check if a diophantine equation has positive solution
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   return b == 0? a : gcd(b, a%b);
}

int main() {
   int a, b, c;
   cin >> a >> b >> c;

   string ans = "No";
   if (c % gcd(a, b) == 0)
      for (int x = 0; x <= 10000; x++)
         // a.x + b.y = c <-> y = (c - ax)/b
         if ((c - a*x)/b >= 0 && (c - a*x) % b == 0) {
            ans = "Yes";
            break;
         }

   cout << ans << endl;
	return 0;
}
