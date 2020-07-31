/*
   graphs > specials
   difficulty: medium
   date: 29/Feb/2020
   problem: given a graph with all vertices with out-degree 1, find the vertice that reaches the most vertices
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjList; // embora cada vértice só tenha 1 adjacente
vector<int> reach;           // reach[v]: qtd de outros vértices que v alcança

#define UNVISITED -1
#define VISITING 0           // vértices do CC atual que estão sendo visitados
#define VISITED 1
vector<int> state;

// calcula reach[u]
int dfs(int u) {
   state[u] = VISITING;

   reach[u] = 0;
   for (int v : adjList[u])
      if (state[v] != VISITING) 
         reach[u] += 1 + dfs(v); // mesmo se v já foi visitado, ainda é preciso recalcular, pois v pode estar no meio de um ciclo e, portanto, não ter recebido reach[v] correto

   state[u] = VISITED;
   return reach[u];
}

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      int V; cin >> V; adjList.assign(V, vector<int>());

      for (int e = 0; e < V; e++) {
         int u, v; cin >> u >> v; u--; v--;
         adjList[u].push_back(v);
      }

      state.assign(V, UNVISITED); reach.assign(V, -1); 
      int maxReach = 0, vMaxReach;

      for (int v = 0; v < V; v++) {
         if (state[v] == UNVISITED) dfs(v);
         if (reach[v] > maxReach) { maxReach = reach[v]; vMaxReach = v; }
      }

      cout << "Case " << t << ": " << vMaxReach+1 << endl;
   }   
   return 0;
}
