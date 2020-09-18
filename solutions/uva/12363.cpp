/*
   graphs > traversal > bridges or articulation points
   difficulty: hard
   date: 27/May/2020
   problem: given an undirected graph, check if there is a unique path between 2 query vertices
   hint: there is a unique path between s and t if the path between them is formed only by bridge edges; for optimize, keep sets for the vertices that are on the same connected component in the pruned graph (with only bridge edges)
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
struct UFDS {
   vector<int> p;
   UFDS(int I) {
      p.assign(I, 0);
      for (int i = 0; i < I; i++) p[i] = i; 
   }
   int findSet(int i) {
      if (p[i] == i) return i;
      return p[i] = findSet(p[i]);
   }
   bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
   }
   void unionSet(int i, int j) {
      int setI = findSet(i);
      int setJ = findSet(j);
      if (!isSameSet(setI, setJ)) p[setI] = setJ;
   }
};

#define UNVISITED -1
#define VISITING 0

vector<vector<int>> adjList;
vector<vector<int>> adjListBridge; // grafo com apenas as arestas q são bridge
vector<int> order, low, parent, state;
int countOrder;

void dfs(int u) {
   state[u] = VISITING;
   low[u] = order[u] = countOrder++;

   for (int v : adjList[u]) {
      if (state[v] == UNVISITED) {
         parent[v] = u;
         dfs(v);
         low[u] = min(low[u], low[v]);
         if (order[u] < low[v]) { // u -> v é bridge
            adjListBridge[u].push_back(v);
            adjListBridge[v].push_back(u);
         }
      }
      else if (v != parent[u])
         low[u] = min(low[u], low[v]);
   }
}

void reach(int u, UFDS &set) {
   state[u] = VISITING;

   for (int v : adjListBridge[u])
      if (state[v] == UNVISITED) {
         set.unionSet(u, v);
         reach(v, set);
      }
}
 
int main() {
   int V, E, Q;
   while (cin >> V >> E >> Q && (V || E || Q)) {
      adjList.assign(V, vector<int>());
      while (E--) {
         int u, v; cin >> u >> v; u--; v--;
         adjList[u].push_back(v);
         adjList[v].push_back(u);
      }

      adjListBridge.assign(V, vector<int>());
      order.resize(V); low.resize(V); parent.resize(V);

      countOrder = 0; state.assign(V, UNVISITED);
      for (int v = 0; v < V; v++) if (state[v] == UNVISITED) dfs(v);


      UFDS sets = UFDS(V);
      state.assign(V, UNVISITED);
      for (int v = 0; v < V; v++) if (state[v] == UNVISITED) reach(v, sets);

      while (Q--) {
         int s, t; cin >> s >> t; s--; t--;
         cout << (sets.isSameSet(s, t)? "Y":"N") << endl;
      }
      cout << "-" << endl;
   }
   return 0;
}
