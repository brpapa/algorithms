/*
   dynamic programming > LCS reduced to LIS
   difficulty: medium
   date: 17/Oct/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

vector<int> C; int N;

int lis() {
   vector<int> size(N);
   vector<int> last(N+1, INF);
   last[0] = -INF;

   int biggest_s = 0;

   for (int j = 0; j < N; j++) {
      int s = lower_bound(last.begin(), last.end(), C[j]) - last.begin();

      if (C[j] < last[s])
         last[s] = C[j];

      size[j] = s;
      biggest_s = max(biggest_s, s);
   }

   return biggest_s;
}

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      int _, P, Q; cin >> _ >> P >> Q; P++; Q++;
      vector<int>A(P); for (int &a: A) cin >> a;
      vector<int>B(Q); for (int &b: B) cin >> b;

      N = Q;
      C.resize(N);
      for (int i = 0; i < N; i++) {
         int p = find(A.begin(), A.end(), B[i]) - A.begin();
         C[i] = p < P? p : -1;
      }

      cout << "Case " << (t++) << ": " << lis() << endl;
   }
	return 0;
}
