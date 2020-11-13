/*
   dynamic programming > LCS reduced to LIS
   difficulty: medium
   date: 06/Nov/2020
   problem: edit distance with only inserting and deleting between two permutations from 1 to N
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

int lis(vector<int> a) {
   int N = a.size();

   vector<int> size(N);
   vector<int> last(N+1, INF);
   last[0] = -INF;

   int biggest_s = 0;

   for (int j = 0; j < N; j++) {
      int s = lower_bound(last.begin(), last.end(), a[j]) - last.begin();

      if (a[j] < last[s])
         last[s] = a[j];

      size[j] = s;
      biggest_s = max(biggest_s, s);
   }

   return biggest_s;
}

int lcs(vector<int> a, vector<int> b) {
   vector<int> rev_a(b.size()+1, -1);
   vector<int> c(b.size());
   for (int i = 0; i < a.size(); i++) rev_a[a[i]] = i;
   for (int i = 0; i < c.size(); i++) c[i] = rev_a[b[i]];
   return lis(c);
}

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N), B(N);
      for (int &a : A) cin >> a;
      for (int &b : B) cin >> b;

      int ans = (N-lcs(A, B)) * 2;
      cout << "Case " << (t++) << ": " << ans << endl;
   }
	return 0;
}

