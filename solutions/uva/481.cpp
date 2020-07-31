/*
   greedy > fast longest increasing subsequence (LIS)
   difficulty: medium
   date: 22/Jan/2020 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   vector<int> A;
   int tmp; while (cin >> tmp) A.push_back(tmp);
   int N = A.size();

   vector<int> L, iL, p(N);

   int jAns = 0;
   for (int j = 0; j < N; j++) {
      int posL = lower_bound(L.begin(), L.end(), A[j]) - L.begin();

      if (posL < L.size()) {
         L[posL] = A[j];    iL[posL] = j;
      } else {
         L.push_back(A[j]); iL.push_back(j);
      }

      p[j] = posL ? iL[posL - 1] : -1;
      if (posL == L.size()-1) jAns = j;
   }

   stack<int> recoveredAns;
   for (int j = jAns; j != -1; j = p[j])
      recoveredAns.push(A[j]);

   cout << L.size() << endl << "-" << endl;
   for (; !recoveredAns.empty(); recoveredAns.pop())
      cout << recoveredAns.top() << endl;   
   return 0;
}
