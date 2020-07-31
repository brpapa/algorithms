/*
   graphs > shortest path > single-source > negative-weighted and cycle graph
   difficulty: medium
   date: 31/Jul/2020
   problem: longest distance from 0 to V-1, checking for positive cycle that are part of that path (0 to V-1)
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1 << 30;

struct Tadj {
	int id, w;
};
vector<vector<Tadj>> adjList;
int V;

vector<ll> ld;

vector<bool> visited;
void dfs(int u) {
   if (visited[u]) return;
   visited[u] = 1;
   for (Tadj v : adjList[u])
      dfs(v.id);
}

/* O(V*E) - retorna true se há um ciclo positivo entre 0 e V-1 */
bool belmman_ford(int s) {
   ld.assign(V, -INF); ld[s] = 0;

   for (int i = 0; i < V; i++) {

      // para cada aresta u --v.w--> v.id
      for (int u = 0; u < V; u++)
         for (Tadj v : adjList[u]) {
            if (ld[u] + v.w > ld[v.id] && ld[u] > -INF) {
               ld[v.id] = ld[u] + v.w;

               // se ainda conseguiu relaxar depois das V-1 vezes anteriores
               if (i == V-1) {
                  visited.assign(V, 0);
                  dfs(v.id);
                  // se o vértice relaxado alcança o caminho 0 à V-1
                  if (visited[0] || visited[V-1]) return true;
               }
            }
         }
   }

   return false;
}

int main() {
   int E, P; cin >> V >> E >> P;
   adjList.assign(V, vector<Tadj>());
   while (E--) {
      int u, v, w; cin >> u >> v >> w; u--; v--; w -= P;
      adjList[u].push_back({v, w});
   }

   cout << (belmman_ford(0)? -1 : max(ld[V-1], 0ll)) << endl;
}