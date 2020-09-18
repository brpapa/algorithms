/*
   graphs > specials > directed acyclic graph (DAG)
   difficulty: easy
   date: 29/May/2020
   problem: counting paths from 0 to V-1
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

int V;
vector<vector<int>> adjList;
vector<int> state;

vector<int> memo;
int dp(int u) {
   if (u == V-1) return 1;

   int &ans = memo[u];
   if (ans != -1) return ans;

   ans = 0;
   for (int v : adjList[u]) ans += dp(v);
   return ans;
}

int main() {
   int t = 0;
   while (cin >> V) {
      if (t++ > 0) cout << endl;
      V++; adjList.assign(V, vector<int>());
      for (int u = 0; u < V-1; u++) {
         int choices; cin >> choices;
         if (choices == 0) adjList[u].push_back(V-1);
         while (choices--) {
            int v; cin >> v;
            adjList[u].push_back(v);
         }
      }

      memo.assign(V, -1);
      cout << dp(0) << endl;
   }
	return 0;
}
