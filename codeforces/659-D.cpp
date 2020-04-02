/*
   computational geometry
   difficulty: easy
   date: 23/Dec/2019 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;

int main() {
   int N;
   cin >> N;
   vector<pair<int, int>> pts(N + 1);

   for (auto &p : pts)
      cin >> p.x >> p.y;

   int ans = 0;
   for (int i = 2; i < pts.size(); i++) {
      // direção: pts[i-2] -> pts[i-1] -> pts[i]

      if (
          (pts[i - 2].x < pts[i - 1].x && pts[i - 1].y < pts[i].y) ||
          (pts[i - 2].y < pts[i - 1].y && pts[i - 1].x > pts[i].x) ||
          (pts[i - 2].x > pts[i - 1].x && pts[i - 1].y > pts[i].y) ||
          (pts[i - 2].y > pts[i - 1].y && pts[i - 1].x < pts[i].x))
         ans++;
   }

   cout << ans;
   return 0;
}