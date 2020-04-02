/*
   dynamic programming > longest increasing subsequence (LIS)
   difficulty: medium
   date: 01/Mar/2020 
   solution: find the max(lis[i]+lds[i]-1) for all i in [0 .. N-1], being i where the subsequence starts
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 2002

vector<int> lis; // lis[i]: tamanho da maior lis começando em A[i]
vector<int> lds; // lds[i]: tamanho da maior lds começando em A[i]

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N; lis.assign(N, 1); lds.assign(N, 1);
      vector<int> A(N); for (int &a : A) cin >> a;

      for (int i = N-1; i >= 0; i--)
         for (int j = i+1; j < N; j++)
            if (A[i] < A[j] && lis[j]+1 > lis[i])
               lis[i] = lis[j]+1;

      for (int i = N-1; i >= 0; i--)
         for (int j = i+1; j < N; j++)
            if (A[i] > A[j] && lds[j]+1 > lds[i])
               lds[i] = lds[j]+1;

      int ans = 0;
      for (int i = 0; i < N; i++) ans = max(ans, lis[i]+lds[i]-1);
      cout << ans << endl;
   }
   return 0;
}
