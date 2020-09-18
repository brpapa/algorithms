/*
   math > matrix exponentiation
   difficulty: easy
   date: 11/Sep/2020
   hint: transform the fibonacci recurrence into a matrix exponentiation
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
ll MOD = 1e9+7;

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

int main() {
   ll n, m;
   while (cin >> n >> m) {
      MOD = 1ll << m;

      if (n == 0) { cout << 0%MOD << endl; continue; }
      if (n == 1) { cout << 1%MOD << endl; continue; }

      matrix B(2, vector<ll>(1)); B[0][0] = 1; B[1][0] = 0;
      matrix T(2, vector<ll>(2, 1)); T[1][1] = 0;
      matrix R = power(T, n-1);
      cout << R[0][0] << endl;
   }
   return 0;
}

/*
f(n) = f(n-1) + f(n-2), para n >= 2
f(0) = 0, f(1) = 1

 | f(n)   | = T * | f(n-1) |
 | f(n-1) |       | f(n-2) |

 | f(n)   | = | 1 1 | * | f(n-1) |
 | f(n-1) |   | 1 0 |   | f(n-2) |

Para n = 2:
 | f(2) | = | 1 1 | * | f(1) |
 | f(1) |   | 1 0 |   | f(0) |

Para n = 3:
 | f(3) | = | 1 1 | * | f(2) |
 | f(2) |   | 1 0 |   | f(1) |

 | f(3) | = | 1 1 | * | 1 1 | * | f(1) |
 | f(2) |   | 1 0 |   | 1 0 |   | f(0) |

Para qualquer n >= 2:
 | f(n)   | = | 1 1 | ^ (n-1) * | f(1) |
 | f(n-1) |   | 1 0 |           | f(0) |
*/