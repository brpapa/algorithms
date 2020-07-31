/*
   searching > binary search
   difficulty: medium
   date: 15/Mar/2020
   problem: given the A and B arrays, count the quantity of pairs i < j such that A[i]+A[j] > B[i]+B[j]
   hint: diff being the A-B array, count, for all i in [0 .. N-2], how many times -diff[i] < diff[j], for all j in [i+1 .. N-1]
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> A(N); for (int &a : A) cin >> a;
   vector<int> B(N); for (int &b : B) cin >> b;

   vector<int> diff(N); for (int i = 0; i < N; i++) diff[i] = A[i]-B[i];
   sort(diff.begin(), diff.end());

   ll ans = 0;
   for (int i = 0; i+1 < N; i++) {
      auto bg = diff.begin() + i + 1;
      ll c = upper_bound(bg, diff.end(), -diff[i]) - bg;
      ans += (diff.end()-bg) - c;
   }
   cout << ans << endl;
   return 0;
}
