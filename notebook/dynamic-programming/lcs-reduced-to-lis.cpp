/*
   LCS reduced to LIS in O(N * log(N))
   
   Motivation: given two permutations A and B of numbers from 1 to N, find their LCS.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

/* input */
vector<int> A = {1,7,5,4,8,3,9,2,6};
vector<int> B = {1,4,3,5,6,2,8,9,7};

//    0 1 2 3 4 5 6 7 8
// A: 1 7 5 4 8 3 9 2 6
// B: 1 4 3 5 6 2 8 9 7
// C: 0 3 5 2 8 7 4 6 1, ou seja, C[i] = index of B[i] in A

// lcs(A, B) is the lis(C)

vector<int> C; int N;

/* O(N * log(N)) */
int lis() {
   vector<int> size(N);
   vector<int> last(N+1, INF);
   last[0] = -INF;

   int biggest_s = 0;

   for (int j = 0; j < N; j++) {
      int s = lower_bound(last.begin(), last.end(), C[j]) - last.begin();

      if (C[j] < last[s])
         last[s] = C[j];

      size[j] = s;
      biggest_s = max(biggest_s, s);
   }

   return biggest_s;
}

/* e.g */
int main() {
   C.resize(B.size());
   for (int i = 0; i < N; i++) {
      int p = find(A.begin(), A.end(), B[i]) - A.begin();
      C[i] = p < A.size()? p : -1;
   }

   cout << lis() << endl;
	return 0;
}
