/*
   greedy
   difficulty: easy
   date: 17/Feb/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> A(N);
   for (int &a : A) cin >> a;
   sort(A.begin(), A.end());

   int ans = 0;
   for (int i = 0; i < A.size(); i += 2)
      ans += A[i+1]-A[i];
   cout << ans << endl;
   return 0;
}