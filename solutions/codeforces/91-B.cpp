/*
   searching > binary search
   difficulty: medium
   date: 31/Mar/2020
   problem: given the array a, compute the array d, where d[i] = j-(i+1) for the max j such that a[j] < a[i]
   hint: apply binary search on preprocessed array mn, filled from right to left
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> a(N), mn(N);
   for (int n = 0; n < N; n++) {
      cin >> a[n];
      mn[n] = a[n];
   }

   for (int n = N-2; n >= 0; n--)
      mn[n] = min(mn[n], mn[n+1]);

   vector<int> d(N);
   for (int n = 0; n < N; n++) {
      auto j = lower_bound(mn.begin()+n+1, mn.end(), a[n]);
      auto i = mn.begin()+n+1;
      d[n] = j - (i+1);
   }

   for (int dv : d) cout << dv << " ";
   return 0;
}