/*
   greedy
   difficulty: easy
   date: 16/Mar/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> A(N); for (int &a: A) cin >> a;
   sort(A.begin(), A.end());

   int ans = 0, timeSoFar = 0;
   for (int n = 0; n < A.size(); n++)
      if (timeSoFar <= A[n])
         timeSoFar += A[n], ans++;
      // se ficou desapontada, deixe-a p o final da fila mesmo (não incrementando timeSoFar)
      
   cout << ans << endl;
   return 0;
}
