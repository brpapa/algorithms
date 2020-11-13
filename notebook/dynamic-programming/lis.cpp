/*
   Motivação: encontre o tamanho da maior subsequência estritamente crescente em A[0..N-1]

   ---
   This problem can be modeled as a DAG and finding the LIS is equivalent to finding the Longest Paths in the implicit DAG.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
vector<int> A = {-7, 10, 5, 2, 3, 8, 8, 1, 2, 3, 4}; int N = 11; 

/*
   Para cada elemento de A:

   -7: last = {-7}
   10: last = {-7, 10}
      5: last = {-7, 5}, pois é uma LIS de tamanho 2 melhor
      2: last = {-7, 2}
      3: last = {-7, 2, 3}
      8: last = {-7, 2, 3, 8}
      8: last = {-7, 2, 3, 8}
      1: last = {-7, 1, 3, 8}, pois no futuro a LIS de tamanho 2 {-7, 1} pode ser extendida, mas a melhor LIS atual (não é L) termina em A[6]=8, ou seja, {-7, 2, 3, 8}
      2: last = {-7, 1, 2, 8}
      3: last = {-7, 1, 2, 3}, melhor LIS atual é {-7, 1, 2, 3}
      4: last = {-7, 1, 3, 3, 4}
*/
/* O(N * log(N)) */
int lis0() {
   vector<int> size(N);        // size[j]: tamanho da LIS que termina com A[j]
   vector<int> last(N+1, INF); // last[s]: último elemento da LIS de tamanho s
   last[0] = -INF;

   int biggest_s = 0;

   for (int j = 0; j < N; j++) {
      // busca o menor s tal que last[s] >= A[j]
      int s = lower_bound(last.begin(), last.end(), A[j]) - last.begin();

      // tenta melhorar o último elemento da LIS de tamanho s
      if (A[j] < last[s]) // estritamente crescente
         last[s] = A[j];

      size[j] = s;
      biggest_s = max(biggest_s, s);
   }

   return biggest_s;
}

/* O(N^2) */
int lis1() {
   vector<int> dp(N, 1); // dp[j]: tamanho da LIS que termina com A[j]
   vector<int> p(N, -1); // p[j]: índice i em A do antecessor de A[j] na LIS

   int best_lis_size = 0;
   int best_j = 0;

   for (int j = 0; j < N; j++) {

      // busca por i (i < j), tal que A[i] < A[j] (estritamente crescente)
      for (int i = j-1; i >= 0; i--)
         if (A[i] < A[j])
            if (dp[i]+1 > dp[j]) {
               dp[j] = dp[i]+1, p[j] = i;
               break;
            }

      // atualiza a resposta
      if (best_lis_size < dp[j]) best_lis_size = dp[j], best_j = j;
   }

   return best_lis_size;
}

int main() {
   cout << lis0() << endl;
   // cout << lis1() << endl;
}
