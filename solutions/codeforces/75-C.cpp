/*
   math > number theory > greatest common divisor (GCD)
   difficulty: medium
   date: 12/Jun/2020
   problem: find the gcd(a, b) that is in a query range [lo .. hi]
   hint: note that all divisors of gcd(a, b) are also divisors of a and b
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   return b == 0? a : gcd(b, a%b);
}

int main() {
   int a, b; cin >> a >> b;
   
   int n = gcd(a, b);
   vector<int> divs;
   for (int i = 1; i*i <= n; i++) {
      if (n%i) continue;

      divs.push_back(i);
      if (n != i*i) divs.push_back(n/i);
   }

   int Q; cin >> Q;
   while (Q--) {
      int lo, hi; cin >> lo >> hi;
      int ans = -1;
      for (int div : divs)
         if (div >= lo && div <= hi)
            ans = max(ans, div);
      cout << ans << endl;
   }
	return 0;
}
