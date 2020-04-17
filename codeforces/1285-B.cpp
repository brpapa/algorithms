/*
   dynamic programming > max 1D range sum > kadane
   difficulty: easy
   date: 10/Jan/2020 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int N;
vector<ll> a; // tastiness

// max subarray sum on [l .. r)
ll kadane(int l, int r) {
   ll maxSoFar = -INF, maxEndingHere = 0;

   for (int i = l; i < r; i++) {
      maxEndingHere = max(maxEndingHere + a[i], 0ll);
      maxSoFar = max(maxSoFar, maxEndingHere);
   }
   return maxSoFar;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T;
   cin >> T;
   while (T--) {
      cin >> N;

      a.resize(N);
      ll totalYasser = 0;
      for (ll &t : a) {
         cin >> t;
         totalYasser += t;
      }

      ll totalAdel = max(kadane(0, N-1), kadane(1, N));
      cout << ((totalYasser > totalAdel)? "YES": "NO") << endl;
   }

   return 0;
}