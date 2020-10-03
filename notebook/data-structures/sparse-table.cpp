/*
   Sparse Table
   
   For efficient range queries on a static array A of size N.
   Common range queries: min, max

   ---

   A função range_combination precisa ser "overlap friendly" (idempotent) pra conseguir implementar range_query em O(1). Mas se ela não for e for associativa (como sum), range_query pode ser implementado ainda em O(log2(N)), continuar vendo em https://youtu.be/uUatD9AudXo?t=877

   f is associative function, if:
      f(a, f(b,c)) = f(f(a,b), c) for all a,b,c

   f is "overlap friendly" function (or idempotent, f(a,a) = a), if:
      f(f(a,b), f(c,d)) = f(a, f(b,c)) for all a,b,c,d
*/
#include <bits/stdc++.h>
using namespace std;
#define pow2(i) (1 << (i)) // 2^i
typedef long long ll;

class sparse_table {
 private:
   vector<ll> A; int N;
   vector<vector<ll>> table; // table[p][n]: answer for the range [n, n+2^p) (size 2^p) in A

   /* O(1) - change here to an "overlap friendly" function */
   ll range_combination(ll a, ll b) {
      return min(a, b);
   }

   /* O(N * log(N)) - fill table with the answers for all ranges in A of size 2^p, for each non-negative integer p such that 2^p <= N */
   void build() {
      int P = (int)floor(log2(N)); // maior P, tal que 2^P <= N
      table.assign(P+1, vector<ll>(N));

      for (int n = 0; n < N; n++) table[0][n] = A[n];
      
      for (int p = 1; p <= P; p++)
         for (int n = 0; n+pow2(p) <= N; n++) {
            // the answer for a range is the union of the answers for 2 sub-ranges (already computed)
            table[p][n] = range_combination(
               table[p-1][n],          // left range of size 2^(p-1)
               table[p-1][n+pow2(p-1)] // right range of size 2^(p-1)
            );
         }
   }

 public:
   sparse_table() {}
   sparse_table(vector<ll> const &A) {
      this->A = A;
      N = (int)A.size();
      build();
   }

   /* O(1) - answer for range query [l, r] in A */
   int range_query(int l, int r) {
      int size = r-l+1;
      int p = (int)floor(log2(size)); // maior p, tal que 2^p <= size
      return range_combination(table[p][l], table[p][r-pow2(p)+1]);
   }
};

/* e.g */
int main() {
   sparse_table st({4,2,3,7,1,5,3,3,9,6,7,-1,4});
   cout << st.range_query(2,7) << endl;
   return 0;
}
