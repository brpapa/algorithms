/*
   dynamic programming
   difficulty: easy
   date: 24/Oct/2020
   hint: use bitmasks
   by: @brpapa
*/
#include <bits/stdc++.h>
#define bit_is_on(S, i) (S & (1 << i))
using namespace std;
typedef long long ll;
const double INF = 1 << 30;

int N;
vector<pair<int,int>> coords;

double dist(pair<int,int> s, pair<int,int> t) {
   double dx = s.first - t.first;
   double dy = s.second - t.second;
   return sqrt(dx*dx + dy*dy);
}

vector<double> memo;
double dp(int mask) {
   // conjunto de estudantes que já estão em um time

   if (mask == (1 << N)-1) return 0;

   double &ans = memo[mask];
   if (ans != -1) return ans;
   
   ans = INF;
   int i = 0; while (bit_is_on(mask, i)) i++;
   for (int j = i+1; j < N; j++)
      if (!bit_is_on(mask, j))
         ans = min(ans, dist(coords[i], coords[j]) + dp(mask | (1 << i) | (1 << j))); 

   return ans;
}

int main() {
   int t = 1;
   while (cin >> N && N) {
      N <<= 1;
      coords.resize(N);
      for (int n = 0; n < N; n++) {
         string _; cin >> _;
         cin >> coords[n].first >> coords[n].second;
      }
      memo.assign(1 << N, -1);
      printf("Case %d: %.2f\n", t++, dp(0));
   }
	return 0;
}
