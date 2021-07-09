/*
   Single Source Shortest Path (SSSP) - Bellman Ford
   
   Motivação: given a possibly-negative weighted and possibly-cycle graph G(V, E), find the shortest distance between a source vertice s and any other vertice.

   Edge case: se o grafo tiver um ciclo negativo, algum sd[u] tenderá à -INF
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<pair<int,int>>> adj_list; // adj_list[u] = {{v, w}, ...}
int V;

/* O(V*E) - retorna a menor distândia de s à t, ou -1, se há um ciclo negativo ou t não é alcançável */
int belmman_ford(int s, int t) {
   vector<int> sd(V, INT_MAX); // sd[u] = shortest distance de s à u
   sd[s] = 0;
   vector<int> parent(V, -1);
   bool was_relaxed = true;

   // assume-se que, se não há ciclos negativos no grafo, deveria levar no máximo V-1 iterações para sd ser ótimo; logo, se for possível relaxar pelo menos mais uma vez, então há ciclos negativos
   for (int _ = 0; was_relaxed && _ < V; _++) {
      was_relaxed = false;

      // para cada aresta u -w-> v
      for (int u = 0; u < V; u++)
         for (auto adj : adj_list[u]) {
            int v = adj.first, w = adj.second;

            if (sd[u] < INT_MAX) {
               // tenta relaxar sd[v]
               if (sd[u] + w < sd[v]) {
                  sd[v] = sd[u] + w;
                  parent[v] = u;
                  was_relaxed = true;
               }
            }
         }
   }

   // tem ciclo negativo alcançável a partir de s, ou t não é alcançável a partir de s
   if (was_relaxed || sd[t] == INT_MAX) return -1;

   return sd[t];
}

int main() {
   V = 3;
   adj_list.assign(V, vector<pair<int,int>>());

   adj_list[0].push_back({1, 10});
   adj_list[1].push_back({2, 15});
   adj_list[2].push_back({2, -40});

   cout << belmman_ford(0, 2) << endl;
   return 0;
}
