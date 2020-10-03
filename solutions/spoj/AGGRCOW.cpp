/*
   data structures > binary search > on answer
   difficulty: medium
   date: 03/Apr/2020
   problem: given an array A of size N (2 <= N <= 10^5), print the largest minimum distance between any two of C (C <= N) elements choosen any
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int N, C;
vector<ll> A; 

// consigo escolher C elementos de A mantendo uma distância mínima entre eles de ans?
bool can(ll ans) {
   int k = 0; // A[k] é o último elemento escolhido
   int c = 1;

   for (int i = 1; i < N && c < C; i++)
      if (A[i]-A[k] >= ans) {
         c++;
         k = i;
      }
   return c >= C;
}

int main() {
   int T; cin >> T;
   while (T--) {
      cin >> N >> C;
      A.resize(N); for (ll &a: A) cin >> a;
      sort(A.begin(), A.end());

      ll low = 0, high = A[N-1]-A[0];
      ll ans;

      while (low <= high) {
         ll mid = (low+high)/2;

         if (can(mid)) low = mid+1, ans = mid;
         else          high = mid-1;
      }
      cout << ans << endl;
   }
   return 0;
}
