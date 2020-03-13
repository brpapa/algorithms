/*
   greedy
   difficulty: easy
   problem: game
   date: 02/Mar/2020
   author: @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> A(N); for (int &a : A) cin >> a;
   sort(A.begin(), A.end());

   if (N % 2) cout << A[N/2] << endl;
   else cout << A[(N-1)/2] << endl;
   return 0;
}