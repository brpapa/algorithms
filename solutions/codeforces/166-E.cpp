/*
   dynamic programming
   difficulty: medium
   date: 02/Feb/2020 
   by: @brpapa
*/
#include <iostream>
using namespace std;

#define ll long long
#define MOD ((int) 1e9+7)

int main() {
   int N; cin >> N;

   ll prevD = 1, prevABC = 0, currD, currABC;
   for (int i = 1; i <= N; i++) {
      currD = (3*prevABC) % MOD;
      currABC = (2*prevABC + prevD) % MOD;

      prevD = currD;
      prevABC = currABC;
   }
   cout << currD << endl;

   return 0;
}

/*
// recursão: dp(N, 0)
ll dp(int i, bool v) {
   // i-ésimo vértice com valor v sendo 0 (é D) ou 1 (é A, B, ou C)

   if (i == 0) return v == 0;

   ll ans = 0;
   if (v == 0) ans += 3*dp(i-1, !v);
   if (v == 1) ans += 2*dp(i-1, v) + dp(i-1, !v);

   return ans % MOD;
}
*/