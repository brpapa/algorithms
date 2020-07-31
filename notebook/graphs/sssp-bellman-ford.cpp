#include <bits/stdc++.h>
using namespace std;

/*
   Motivação: dado um possibly-negative weighted and possibly-cycle graph G(V, E), encontre a shortest distance entre um vértice origem s e qualquer outro vértice.

   Edge case: se o grafo tiver um ciclo negativo, algum sd[u] tenderá à -INF
*/

/* inputs */
struct Tadj {
   int id, w;
};
vector<vector<Tadj>> adj_list;
int V;

/* outputs */
vector<int> sd; // sd[u]: shortest distance de s à u

/* O(V*E) - retorna true se há um ciclo negativo em qualquer lugar do grafo */
bool belmman_ford(int s) {
   sd.assign(V, INT_MAX); sd[s] = 0;
   bool relaxed = true;

   // se não há ciclos negativos no grafo, deve levar no máximo V-1 iterações para sd ser ótimo
   // se for possível relaxar ainda mais, então há ciclos negativos
   for (int _ = 0; relaxed && _ < V; _++) {
      relaxed = false;

      // para cada aresta u --v.w--> v.id
      for (int u = 0; u < V; u++)
         for (Tadj v : adj_list[u])
            if (sd[u] < INT_MAX) {
               // tenta relaxar sd[v.id]
               if (sd[u] + v.w < sd[v.id]) {
                  sd[v.id] = sd[u] + v.w;
                  relaxed = true;
               }
            }
   }

   return relaxed;
}

/* e.g */
int main() {
   int E, s; cin >> V >> E >> s;
   adj_list.assign(V, vector<Tadj>());
   while (E--) {
      int u, v, w; cin >> u >> v >> w;
      adj_list[u].push_back({v, w});
   }
   cout << belmman_ford(s);
}

/*
Graph with negative weight, but no negative cycle
5 5 0
0 1 1
0 2 10
1 3 2
2 3 -10
3 4 3

Graph with negative cycle
3 3 0
0 1 1000
1 2 15
2 1 -42
*/