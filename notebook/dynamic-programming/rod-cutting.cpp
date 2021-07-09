/*
   Motivation: given a rod of length N and the prices of all pieces of size smaller than N, determine the maximum value obtainable by cutting up the rod and selling the pieces. 
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
vector<int> prices = {1, 5, 8, 9}; // prices[i] = price of rod of length i+1
int N = prices.size();

vector<int> memo;

/* O(N^2) */
int dp(int n) {
   // rod with remaining length n

   if (n == 0) return 0;

   int &ans = memo[n];
   if (ans != -1) return ans;

   ans = -INF;
   for (int i = 0; i < n; i++)
      ans = max(ans, prices[i] + dp(n-(i+1)));

   return ans;
}

int main() {
   memo.assign(N+1, -1);
   cout << dp(N) << endl;
}
