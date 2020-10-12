/*
   graphs > specials > bipartite > bipartite checking
   difficulty: easy
   date: 31/Jan/2020 
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
   int V;
   while (cin >> V) {
      if (V == 0) break;
      vector<int> adjList[202];

      int E; cin >> E;
      while (E--) {
         int v1, v2; cin >> v1 >> v2;
         adjList[v1].push_back(v2);
      }

      vector<int> color(V, -1); color[0] = 0;
      queue<int> q; q.push(0);
      bool isBipartite = true;

      while (!q.empty() && isBipartite) {
         int v = q.front(); q.pop();

         for (int u : adjList[v]) {
            if (color[u] == -1) {       // cor ainda não definida (não visitado)
               color[u] = 1 - color[v]; // 1 ou 0
               q.push(u);
            } else if (color[u] == color[v]) { // conflito de cor
               isBipartite = false;
               break;
            }
         }
      }
      cout << (isBipartite? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
   }
   return 0;
}
