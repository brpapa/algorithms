/*
   graphs
   problem: design labirints
   date: 05/May/2019
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#define MAX_V 100
using namespace std;

vector<int> adj[MAX_V];

// verifica se existe aresta (v, u)
bool isAdj(int v, int u) {
   for (int i = 0; i < adj[v].size(); i++)
      if (u == adj[v][i])
         return true;
   return false;
}

int main() {
   int T, V, E, n, v, a;
   scanf("%d", &T);
   while (T--) {
      scanf("%d", &n); //nó inicial e final
      scanf("%d %d", &V, &E);

      for (int i = 0; i < V; i++)
         adj[i].clear();

      int qtePassosIda = 0;
      for (int e = 0; e < E; e++) {
         scanf("%d %d", &v, &a);
         if (isAdj(v, a))
            continue;

         adj[v].push_back(a);
         adj[a].push_back(v);
         qtePassosIda++;
      }
      printf("%d\n", qtePassosIda * 2);
   }
   return 0;
}