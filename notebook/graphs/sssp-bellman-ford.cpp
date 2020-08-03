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
   V = 3;
   adj_list.assign(V, vector<Tadj>());

   adj_list[0].push_back({1, 10});
   adj_list[1].push_back({2, 15});
   adj_list[2].push_back({2, -40});

   cout << belmman_ford(0);
   return 0;
}
