/*
   math > number theory > module arithmetic
   difficulty: easy
   date: 15/Jun/2020
   problem: compute (a^n) % m, where a <= 2^31 and n <= 2^31
   hint: use fast power with mod
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastPower(ll a, ll n, int m) {
   if (n == 0) return 1;
   if (n % 2 == 0) return fastPower((a*a)%m, n/2, m) % m;
   return ((a%m) * fastPower((a*a)%m, (n-1)/2, m)) % m;
}

int main() {
   ll a, n; int m;
   while (cin >> a >> n >> m)
      cout << fastPower(a, n, m) << endl;
   return 0;
}
