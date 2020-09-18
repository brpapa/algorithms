/*
   math > combinatorics
   difficulty: easy
   date: 17/Jun/2020
   problem: find the max difference between numbers of a given array and the number of ways to get it
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N; cin >> N;
   vector<int> A(N); for (int &a : A) cin >> a;
   sort(A.begin(), A.end());

   int mn = A.front(); ll qtyMn = 0;
   int mx = A.back(); ll qtyMx = 0;

   for (int i = 0; i < N && A[i] == mn; i++) qtyMn++;
   for (int i = N-1; i >= 0 && A[i] == mx; i--) qtyMx++;

   cout << mx-mn << " " << (mn < mx? qtyMn*qtyMx : qtyMn*(qtyMn-1)/2) << endl;
   return 0;
}
