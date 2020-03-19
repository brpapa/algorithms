/*
   dynamic programming > 0-1 knapsack > subset sum
   difficulty: easy
   date: 07/Feb/2020
   problem: check if any subset of A has a sum equal to K
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K;
vector<int> A;

int memo[101][5000];

bool dp(int n, int k) {
   // n-ésimo número de A, soma acumulada k

   if (k == K) return 1;
   if (n == N || k > K) return 0;

   int &ans = memo[n][k];
   if (ans != -1) return ans;

   return ans = dp(n+1, k) || dp(n+1, k+A[n]);
}

int main() {
   while (cin >> N >> K) {
      A.assign(N, 0);
      memset(memo, -1, sizeof memo);

      for (int k = 0; k < K; k++) {
         int n;
         cin >> n; A[n-1]++;
         cin >> n; A[n-1]++;
      }
      cout << (dp(0, 0)? 'S' : 'N') << endl;
   }
   return 0;
}