/*
   dynamic programming
   difficulty: easy
   date: 03/Oct/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 50;

/*
   1f -> 1m
   1m -> 1m 1f

   0: 1f+0f 0m
   1: 1f+0f 1m
   2: 1f+1f 2m
   3: 1f+2f 4m
   4: 1f+4f 7m
*/

vector<ll> memo_m;
ll m(int n) {
   if (n == 0) return 0;
   if (n == 1) return 1;

   ll &ans = memo_m[n];
   if (ans != -1) return ans;

   return ans = m(n-1) + m(n-2) + 1; // m(n-1) + f(n-1)
}

vector<ll> memo_f;
ll f(int n) {
   if (n == 0) return 1;

   ll &ans = memo_f[n];
   if (ans != -1) return ans;

   return ans = m(n-1)+1;
}

int main() {
   memo_m.assign(MAX_N, -1); memo_f.assign(MAX_N, -1);

   int n;
   while (cin >> n && n != -1) {
      cout << m(n) << " " << m(n)+f(n) << endl;
   }
	return 0;
}
