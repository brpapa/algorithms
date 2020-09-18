/*
   greedy
   difficulty: easy
   date: 23/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N;
   while (cin >> N && N) {
      vector<int> A(N); for (int &a : A) cin >> a;

      ll cost = 0;
      for (int i = 0; i+1 < N; i++)
         A[i+1] += A[i], cost += abs(A[i]);

      cout << cost << endl;
   }
   return 0;
}
