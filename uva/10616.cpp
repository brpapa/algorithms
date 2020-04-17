/*
   dynamic programming > 0-1 knapsack > subset sum
   difficulty: medium
   date: 24/Jan/2020 
   problem: given an array of size N, count how many subsets of size M have their sum divisible by D
   solution: use module arithmetic
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

ll A[222];
int N, D, M;

ll memo[222][22][22];
ll dp(int n, int m, int sum) {
   // número atual A[n], soma sum (até D) do subconjunto de tamanho m

   if (m == M) return (ll) sum == 0; // subconjunto e tamanho M com soma divisível por D
   if (n == N) return 0ll;

   ll &ans = memo[n][m][sum];
   if (ans != -1) return ans;

   // como sum é indice de memo, não posso passar com valor negativo!
   int newSum = (sum+A[n]) % D;
   if (newSum < 0) newSum += D; // equivale

   return ans = dp(n+1, m+1, newSum) + dp(n+1, m, sum);
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T = 0;
   while (true) {
      int Q; cin >> N >> Q;
      if (!N && !Q) return 0;
      
      for (int i = 0; i < N; i++) cin >> A[i];

      printf("SET %d:\n", ++T);
      for (int i = 1; i <= Q; i++) {
         cin >> D >> M;
         memset(memo, -1, sizeof memo);
         printf("QUERY %d: %lld\n", i, dp(0, 0, 0));
      }

   }
}
