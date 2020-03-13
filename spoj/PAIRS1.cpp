/*
   greedy
   difficulty: easy
   problem: count the pairs
   date: 02/Mar/2020
   solution: apply binary search on the sorted array by the added value
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;

int bs(int l, int r, int value) {
   if (l > r) return -1;

   int m = (l + r) / 2;
   if (value < A[m]) return bs(l, m-1, value);
   if (value > A[m]) return bs(m+1, r, value);

   return m;
}

int main() {
   int N, K; cin >> N >> K; 
   A.resize(N); for (int &a : A) cin >> a;
   
   sort(A.begin(), A.end());

   int count = 0;
   for (int n = 0; n < N; n++)
      if (bs(n, N-1, A[n]+K) != -1)
         count++;
   cout << count << endl;
   return 0;
}