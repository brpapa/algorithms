/*
   data structures > binary search
   difficulty: easy
   date: 02/Mar/2020
   problem: given the A array, count the quantity of pairs i < j such that A[i]-A[j] == K
   hint: search on the sorted array A by the A[n]+K, for all n in [0 .. N-1]
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N, K; cin >> N >> K; 
   vector<int> A(N); for (int &a : A) cin >> a;
   sort(A.begin(), A.end());

   int count = 0;
   for (int n = 0; n < N; n++)
      if (binary_search(A.begin()+n, A.end(), A[n]+K))
         count++;
   cout << count << endl;
   return 0;
}