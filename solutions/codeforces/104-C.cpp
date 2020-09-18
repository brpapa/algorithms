/*
   graphs > traversal > edge classification
   difficulty: easy
   date: 26/Mar/2020
   problem: check if the given undirected graph can be represented as a set of three or more rooted trees, whose roots are connected by a simple cycle
   hint: check if the graph is connective and has only one cycle
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define UNVISITED -1
#define VISITING 0
#define VISITED 1

vector<int> adjList[110];
int state[110];
int parent[110];
int qtyCycles, qtyCCs;

void dfs(int u) {
   state[u] = VISITING;

   for (int v : adjList[u]) {
      if (state[v] == UNVISITED)
         parent[v] = u, dfs(v);
      else if (state[v] == VISITING && v != parent[u])
         qtyCycles++;
   }
   state[u] = VISITED;
}

int main() {
   int V, E; cin >> V >> E;
   memset(state, UNVISITED, sizeof state);
   memset(parent, -1, sizeof parent);

   while (E--) {
      int u, v; cin >> u >> v; u--; v--;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
   }

   qtyCycles = 0, qtyCCs = 0;
   for (int u = 0; u < V; u++)
      if (state[u] == UNVISITED)
         dfs(u), qtyCCs++;
   cout << (qtyCycles == 1 && qtyCCs == 1? "FHTAGN!" : "NO") << endl;
   return 0;
}
