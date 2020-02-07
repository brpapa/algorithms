/*
   graphs > bridges and articulation points
   difficulty: easy
   problem: critical links
   date: 04/Feb/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<vector<int>> adjList;

vector<int> num, low, parent;

int countNum;
vector<pair<int, int>> bridgeEdges;

void dfs(int v) {
   low[v] = num[v] = countNum++;

   for (int u : adjList[v]) {
      if (num[u] == -1) {
         parent[u] = v;
         dfs(u);

         low[v] = min(low[v], low[u]);
         if (num[v] < low[u])
            bridgeEdges.push_back(pair<int,int>(min(v, u), max(v, u)));
      }
      else if (u != parent[v]) // back edge not direct
         low[v] = min(low[v], low[u]);
   }
}

int main() {
   while (cin >> V) {
      countNum = 0; adjList.assign(V, vector<int>()); bridgeEdges.clear();
      num.assign(V, -1); low.assign(V, -1); parent.assign(V, -1);

      for (int i = 0; i < V; i++) {
         int v, e; scanf("%d (%d) ", &v, &e);
         while (e--) {
            int u; cin >> u;
            adjList[v].push_back(u);
         }
      }
      
      for (int v = 0; v < V; v++)
         if (num[v] == -1)
            dfs(v);

      sort(bridgeEdges.begin(), bridgeEdges.end());
      printf("%d critical links\n", bridgeEdges.size());
      for (auto edge : bridgeEdges)
         printf("%d - %d\n", edge.first, edge.second);
      cout << endl;
   }

   return 0;
}
