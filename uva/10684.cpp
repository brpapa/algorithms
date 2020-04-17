/*
   dynamic programming > max 1D range sum > kadane
   difficulty: easy
   date: 17/Jan/2020 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#define INF (int)0x3f3f3f3f
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   while (true) {
      int N; cin >> N;
      if (!N) break;

      vector<int> arr(N);
      for (int &a : arr) cin >> a;

      int ans = -INF, sumAcc = 0;
      for (int i = 0; i < N; i++) {
         sumAcc = max(arr[i], sumAcc+arr[i]);
         ans = max(ans, sumAcc);
      }
      if (ans > 0) cout << "The maximum winning streak is " << ans;
      else cout << "Losing streak";
      cout << ".\n";
   }
   return 0;
}
