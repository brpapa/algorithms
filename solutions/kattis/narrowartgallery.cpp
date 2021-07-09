/*
   dynamic programming
   difficulty: easy
   date: 08/Jul/2021
   problem: narrow art gallery
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define min3(a, b, c) ((a) < (b) ? min(a, c) : min(b, c))
typedef long long ll;
const int INF = 1 << 30;

int N;
int K;
vector<pair<int, int>> rooms;

enum { LEFT, RIGHT, NONE };

int memo[202][202][3];
int dp(int i, int k, int prev_selected) {
   if (k == K) return 0;
   if (i == N && k < K) return INF;

   int &ans = memo[i][k][prev_selected];
   if (ans != -1) return ans;

   ans = dp(i+1, k, NONE);
   if (prev_selected != RIGHT) ans = min(ans, rooms[i].first + dp(i+1, k+1, LEFT));
   if (prev_selected != LEFT)  ans = min(ans, rooms[i].second + dp(i+1, k+1, RIGHT));

   return ans;
}

int main() {
   while (cin >> N >> K && (N || K)) {
      rooms.resize(N);
      memset(memo, -1, sizeof memo);
      int sum = 0;
      for (auto &room : rooms) {
         cin >> room.first >> room.second;
         sum += room.first + room.second;
      }

      cout << sum - dp(0, 0, NONE) << endl;
   }
   return 0;
}