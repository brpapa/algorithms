/*
   searching > segment tree
   difficulty: easy
   date: 18/Sep/2020
   problem: range product query
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class seg_tree {
 private:
   vector<ll> A; int N;
   vector<ll> bin_tree; 

   int le(int v) { return (v << 1) + 1; } 
   int ri(int v) { return (v << 1) + 2; } 

   ll range_combination(ll a, ll b) {
      return a*b;
   }

   void build(int v, int l, int r) {      
      if (l == r) { bin_tree[v] = A[l]; return; } 

      int m = (l + r) / 2;
      build(le(v), l, m+0);
      build(ri(v), m+1, r);

      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

   ll range_query(int v, int l, int r, int ql, int qr) {
      if (ql > r || qr < l) return 1; 
      if (l >= ql && r <= qr) return bin_tree[v];
      
      int m = (l + r) / 2;
      return range_combination(
         range_query(le(v), l, m+0, ql, qr),
         range_query(ri(v), m+1, r, ql, qr)
      );
   }

   void point_set(int v, int l, int r, int i, ll diff) {
      if (i > r || i < l) return;
      if (l == r) { bin_tree[v] = diff, A[l] = diff; return; }
      
      int m = (l + r) / 2;
      point_set(le(v), l, m+0, i, diff);
      point_set(ri(v), m+1, r, i, diff);
      
      bin_tree[v] = range_combination(bin_tree[le(v)], bin_tree[ri(v)]);
   }

 public:
   seg_tree() {}
   seg_tree(vector<ll> const &A) {
      this->A = A;
      N = (int)A.size();
      bin_tree.assign(4*N, 0);
      build(0, 0, N-1);
   }

   ll range_query(int ql, int qr) {
      return range_query(0, 0, N-1, ql, qr);
   }

   void point_set(int i, ll diff) {
      point_set(0, 0, N-1, i, diff);
   }
};

int main() {
   int N, K;
   while (cin >> N >> K) {
      vector<ll> A(N); for (ll &a: A) { cin >> a; if (a > 0) a = 1; if (a < 0) a = -1; }
      seg_tree st(A);

      string ans;
      while (K--) {
         char cmd; cin >> cmd;
         if (cmd == 'C') {
            int i; ll v; cin >> i >> v; i--; if (v > 0) v = 1; if (v < 0) v = -1;
            st.point_set(i, v);
         }
         if (cmd == 'P') {
            int l, r; cin >> l >> r; l--; r--;
            ll res = st.range_query(l, r);
            if (res == 0) ans.append("0");
            else if (res > 0) ans.append("+");
            else if (res < 0) ans.append("-");
         }
      }
      cout << ans << endl;
   }
   return 0;
}
