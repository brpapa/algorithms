/*
   graphs > specials > tree
   difficulty: easy
   date: 19/May/2020
   problem: given a forest, find the length of the longest path
   by: @brpapa
*/
#include <bits/stdc++.h>
#define UNVISITED 0
#define VISITING 1
using namespace std;

vector<vector<int>> adjList;
vector<int> state;
int maxLvl;

void dfs(int u, int lvl) {
   state[u] = VISITING;
   maxLvl = max(maxLvl, lvl);

   for (int v : adjList[u])
      if (state[v] == UNVISITED)
      dfs(v, lvl+1);
}

int main() {
   int V; cin >> V;
   adjList.assign(V, vector<int>()); state.assign(V, UNVISITED);
   vector<bool> isRoot(V, false);

   for (int v = 0; v < V; v++) {
      int u; cin >> u; 
      if (u > -1) adjList[u-1].push_back(v);
      else isRoot[v] = true;
   }

   maxLvl = 0;
   for (int u = 0; u < V; u++)
      if (isRoot[u] && state[u] == UNVISITED)
         dfs(u, 1);

   cout << maxLvl << endl;
   return 0;
}
