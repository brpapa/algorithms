/*
   dynamic programming > longest increasing subsequence (LIS)
   difficulty: medium
   date: 23/Jan/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <cmath>
#include <vector>
#define INF (int)0x7f7f7f7f
using namespace std;

struct T {
   int x, y, t;
   T() {}
   T(int x, int y, int t) : x(x), y(y), t(t) {}
};
vector<T> v;

vector<int> memo;
int lis(int j) {
   int &ans = memo[j];
   if (ans != -1) return ans;

   if (j == 0) return 0;

   ans = -INF; // pois, se não conter a posição inicial v[0], a lis é inválida
   for (int i = 0; i < j; i++)
      if (v[j].t - v[i].t >= max(abs(v[i].x-v[j].x), abs(v[i].y-v[j].y)))
         // tempo é suficiente p se deslocar de v[i] à v[j]
         ans = max(ans, 1 + lis(i));
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   while (true) {
      int N, M, K; cin >> N >> M >> K;
      if (!N && !M && !K) break;

      v.resize(K+1);
      memo.assign(K+1, -1);

      int x, y, t;
      for (int i = 1; i < v.size(); i++) {
         cin >> x >> y >> t;
         v[i] = T(x, y, t);
      }
      cin >> x >> y;
      v[0] = T(x, y, 0);

      int ans = 0;
      for (int i = 0; i < v.size(); i++)
         ans = max(ans, lis(i));
      cout << ans << endl;
   }
   return 0;
}