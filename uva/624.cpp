/*
   dynamic programming > 0-1 knapsack > subset sum
   difficulty: easy
   date: 24/Mar/2020
   problem: print the subset of A with the max sum k, k <= K
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define INF (1 << 30)
using namespace std;

int A[22], N, K;

int memo[22][22*22*22];
int dp(int n, int k) {
   // n-ésimo elemento de A, soma acumulada k

   if (k > K)  return -INF;

   int &ans = memo[n][k];
   if (ans != -1) return ans;

   if (n == N) return ans = k;

   return ans = max(dp(n+1, A[n]+k), dp(n+1, k));
}

void recover() {
   int k = 0;
   for (int n = 0; n < N; n++) {
      if (memo[n+1][k+A[n]] >= memo[n+1][k])  {
         k += A[n];
         cout << A[n] << " ";
      }
   }
   cout << "sum:" << k << endl;
}

int main() {
   while (cin >> K) {
      cin >> N; for (int n = 0; n < N; n++) cin >> A[n];

      memset(memo, -1, sizeof memo);
      dp(0, 0);
      recover();
   }
   return 0;
}
