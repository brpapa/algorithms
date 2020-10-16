/*
   DP optimization - Matrix Exponentiation/Power

   Motivação: calcule f(n), sendo n < 10^18 e f uma função linear de recorrência.
   
   ---
   https://www.quora.com/q/threadsiiithyderabad/Solving-Dynamic-Programming-with-Matrix-Exponentiation
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1e9+7;

/* O(N^2) - returns I which is NxN */
matrix identity(int N) {
   matrix I(N, vector<ll>(N, 0));
   for (int n = 0; n < N; n++) I[n][n] = 1;
   return I;
}

/* O(N^3) - returns A*B which is LxC, where A is LxN and B is NxC */
matrix mult(const matrix& A, const matrix& B) {
   int L = A.size(), C = B[0].size(), N = B.size();
   matrix R(L, vector<ll>(C, 0));

   for (int l = 0; l < L; l++)
      for (int c = 0; c < C; c++)
         for (int k = 0; k < N; k++)
            R[l][c] = (R[l][c] + A[l][k] * B[k][c]) % MOD;

   return R;
}

/* O(N^3 * log(k)) - returns A^k, where A is NxN */
matrix power(matrix A, ll k) {
   matrix R = identity(A.size());

   while (k > 0) {
      if (k & 1ll) R = mult(R, A); // if k is odd

      k >>= 1ll;
      A = mult(A, A);
   }

   return R;
}

/*
Sendo a,b e c constantes:
f(n) = a*f(n-1) + b*f(n-2) + c*f(n-3), se n >= 3
f(0) = 0, f(1) = 1, f(2) = 1

Defina a matriz T de forma que: (pois a da direita é a "próxima" da esquerda)
 | f(n)   | = T * | f(n-1) |
 | f(n-1) |       | f(n-2) |
 | f(n-2) |       | f(n-3) |

 | f(n)   | = | a b c | * | f(n-1) |
 | f(n-1) |   | 1 0 0 |   | f(n-2) |
 | f(n-2) |   | 0 1 0 |   | f(n-3) |


Para n = 3:
 | f(3) | = | a b c | * | f(2) |
 | f(2) |   | 1 0 0 |   | f(1) |
 | f(1) |   | 0 1 0 |   | f(0) |

Para n = 4:
 | f(4) | = | a b c | * | f(3) |
 | f(3) |   | 1 0 0 |   | f(2) |
 | f(2) |   | 0 1 0 |   | f(1) |

 | f(4) | = | a b c | * | a b c | * | f(2) |
 | f(3) |   | 1 0 0 |   | 1 0 0 |   | f(1) |
 | f(2) |   | 0 1 0 |   | 0 1 0 |   | f(0) |
            ------ 2 times ------

Para qualquer n >= 3:
 | f(n)   |  =  | a b c | * ... * | a b c | * | 1 |
 | f(n-1) |     | 1 0 0 |         | 1 0 0 |   | 1 |
 | f(n-2) |     | 0 1 0 |         | 0 1 0 |   | 0 |
                -------- n-2 times --------
*/
