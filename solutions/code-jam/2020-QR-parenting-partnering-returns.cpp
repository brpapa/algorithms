/*
   greedy
   difficulty: easy
   date: 04/Apr/2020
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ta {
   int s, e, i;
   Ta() {}
   Ta(int s, int e, int i) : s(s), e(e), i(i) {}

   bool operator<(const Ta &p) const {
      return s < p.s;
   }
};

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<Ta> A(N);
      for (int i = 0; i < N; i++) cin >> A[i].s >> A[i].e, A[i].i = i;
      sort(A.begin(), A.end());

      bool hasSolution = true;

      vector<char> sortedSolution(N);
      int eLastC = 0, eLastJ = 0;

      for (int i = 0; i < N && hasSolution; i++) {
         if (A[i].s >= eLastC)      sortedSolution[i] = 'C', eLastC = A[i].e;
         else if (A[i].s >= eLastJ) sortedSolution[i] = 'J', eLastJ = A[i].e;
         else hasSolution = false;
      }

      cout << "Case #" << (t++) << ": ";

      if (!hasSolution) {
         cout << "IMPOSSIBLE" << endl;
      }
      else {
         vector<char> ans(N);
         for (int i = 0; i < N; i++) ans[A[i].i] = sortedSolution[i];
         for (char a : ans) cout << a;
         cout << endl;
      }
   }
   return 0;
}