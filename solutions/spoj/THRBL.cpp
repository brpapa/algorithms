/*
   data structures > sparse table
   difficulty: easy
   date: 03/Oct/2020
   problem: range max query
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define pow2(i) (1 << (i))
typedef long long ll;

class sparse_table {
 private:
   vector<ll> A; int N;
   vector<vector<ll>> table;

   ll range_combination(ll a, ll b) {
      return max(a, b);
   }

   void build() {
      int P = (int)floor(log2(N));
      table.assign(P + 1, vector<ll>(N));

      for (int n = 0; n < N; n++)
         table[0][n] = A[n];

      for (int p = 1; p <= P; p++)
         for (int n = 0; n + pow2(p) <= N; n++) {
            table[p][n] = range_combination(
                table[p - 1][n],
                table[p - 1][n + pow2(p - 1)]);
         }
   }

 public:
   sparse_table() {}
   sparse_table(vector<ll> const &A) {
      this->A = A;
      N = (int)A.size();
      build();
   }

   int range_query(int l, int r) {
      int size = r - l + 1;
      int p = (int)floor(log2(size));
      return range_combination(table[p][l], table[p][r - pow2(p) + 1]);
   }
};

int main() {
   int N, M;
   while (cin >> N >> M) {
      vector<ll> A(N); for (ll &a : A) cin >> a;

      sparse_table st(A);
      ll ans = 0;

      while (M--) {
          int l , r; cin >> l >> r; l--; r--;

         if (r - l <= 1 || A[l] >= st.range_query(l + 1, r - 1))
            ans++;
      }

      cout << ans << endl;
   }
   return 0;
}
