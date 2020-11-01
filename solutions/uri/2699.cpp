/*
   dynamic programming
   difficulty: medium
   date: 26/Oct/2020
   problem: given a 1000-digit number S with some digits hidden, determine the minimum S possible such that S % N == 0
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

string s, recovered;
int N;

vector<vector<int>> memo;
int solve(int i, int acc) {
   if (i == s.size()) return acc == 0;

   int &ans = memo[i][acc];
   if (ans != -1) return ans;

   if (s[i] != '?')
      return solve(i + 1, (acc * 10 + s[i] - '0') % N);

   for (int x = (i == 0); x < 10; x++) {
      if (solve(i + 1, (acc * 10 + x) % N)) {
         recovered[i] = '0' + x;
         return ans = 1;
      }
   }
   return ans = 0;
}

int main() {
   cin >> s >> N;
   recovered = s;
   memo.assign(s.size(), vector<int>(N, -1));
   cout << (solve(0, 0) ? recovered : "*") << endl;
}