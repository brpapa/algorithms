/*
   Topological sort
   
   Motivação: dado um directed graph, encontre qualquer sequência linear de vértices, tal que, se nela u vem antes de v, existe um caminho u -> v. 
   
   Non-solution case: quando o grafo contém ciclo
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
int V = 8;
vector<vector<int>> adj_list = {
   {},
   {5, 2},
   {2, 4},
   {6, 5},
   {5},
   {2},
   {7},
   {5}
};

/* output */
vector<int> ts; // vértices em ordem topológica

enum { UNVISITED, VISITING, VISITED };
vector<int> state;
stack<int> s;

/* O(V+E) - return true if a cycle is found from u */
bool dfs(int u) {
   state[u] = VISITING;

   for (int v : adj_list[u]) {
      if (state[v] == UNVISITED) {
         if (dfs(v))
            return true;
      }
      else if (state[v] == VISITING)
         return true;
   }

   state[u] = VISITED;
   s.push(u);
   return false;
}

/* O(V+E) - return true if a topological sorting exists */
bool topo_sort() {
   while (!s.empty()) s.pop();
   state.assign(V, UNVISITED);

   for (int u = 0; u < V; u++)
      if (state[u] == UNVISITED)
         if (dfs(u))
            return false;

   ts.clear(); 
   while (!s.empty())
      ts.push_back(s.top()), s.pop();
   return true;
}

int main() {
   if (topo_sort())
      // use ts here

   return 0;
}
