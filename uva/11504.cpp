/*
   graphs > strongly connected components (SCC)
   difficulty: medium
   problem: dominos
   date: 07/Feb/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adjList;

#define UNVISITED -1
#define VISITING 0 // visitado, mas ainda visitando seus adjacentes
#define VISITED 1  // todos seus adjacentes visitados e já faz parte de um SCC
vector<int> state;

vector<int> order;
vector<int> low;

stack<int> s; // vértices atuais que estão sendo VISITING (na ordem de visitação)
int countOrder, countSCC;

vector<int> scc; // scc[v]: scc em que v faz parte


void dfs(int v) {
   low[v] = order[v] = countOrder++;
   state[v] = VISITING; s.push(v);

   for (int u : adjList[v]) {
      if (state[u] == UNVISITED) dfs(u);
      if (state[u] == VISITING)  low[v] = min(low[v], low[u]);
   }

   if (low[v] == order[v]) {
      int u;
      do {
         u = s.top(); s.pop();
         state[u] = VISITED;
         scc[u] = countSCC;
      } while (u != v);

      countSCC++;
   }
}

int main() {
   int T; cin >> T;
   while (T--) {
      int V, E; cin >> V >> E;

      countOrder = countSCC = 0;
      order.resize(V); low.resize(V); state.assign(V, UNVISITED); scc.resize(V);
      adjList.assign(V, vector<int>());

      while (E--) {
         int v, u; cin >> v >> u; v--; u--;
         adjList[v].push_back(u);
      }

      for (int v = 0; v < V; v++)
         if (state[v] == UNVISITED)
            dfs(v);
      
      // contando o número de SCCs que não recebem arestas vindas de outro SCC
      int ans = countSCC;
      vector<bool> x(countSCC, false);

      for (int v = 0; v < V; v++)
         for (int u : adjList[v])
            if (scc[v] != scc[u] && !x[scc[u]]) {
               ans--;
               x[scc[u]] = true;
            }
      cout << ans << endl;
   }   
   return 0;
}
