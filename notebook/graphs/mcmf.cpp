/*
   Minimum Cost Maximum Flow (MCMF) - fluxo máximo de menor custo

   Motivação: encontrar o fluxo máximo (<= K) com o menor custo possível. Cada aresta dada possui, além da capacidade máxima, um peso, que se refere ao custo por unidade de fluxo.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
vector<vector<tuple<int,ll,ll>>> adj_list; // adj_list[u]: {{v, weight, capacity}, ...}
int V;

vector<vector<tuple<int,ll,ll,ll>>> new_adj_list; // new_adj_list[u]: {{v, weight, remaining_capacity, flow}, ...}
vector<pair<int,int>> parent;        // parent[v]: {u, índice de new_adj_list[u]}
vector<vector<int>> rev_idx;

/* O(V*E) - find the shortest augmenting path (in terms of weight) and returns your bottleneck, or 0, if there is no more an augmenting path */
ll belmman_ford(int s, int t) {
   parent.assign(V, {-1, -1});

   vector<ll> sd(V, INT_MAX); // sd[u]: shortest distance de s à u
   sd[s] = 0;
   bool was_relaxed = true;

   // se não há ciclos negativos no grafo, deveria levar no máximo V-1 iterações para sd ser ótimo
   // se for possível relaxar ainda mais, então há ciclos negativos
   for (int _ = 0; was_relaxed && _ < V; _++) {
      was_relaxed = false;

      // para cada aresta u --(w,c)--> v, com c > 0
      for (int u = 0; u < V; u++)
         for (int i = 0; i < new_adj_list[u].size(); i++) {
            int v; long long w,c,__; tie(v,w,c,__) = new_adj_list[u][i];

            if (sd[u] < INT_MAX && c > 0) {
               // tenta relaxar sd[v]
               if (sd[u] + w < sd[v]) {
                  sd[v] = sd[u] + w;
                  parent[v] = {u,i};
                  was_relaxed = true;
               }
            }
         }
   }

   // se tem ciclo negativo ou t não é alcançável a partir de s
   if (was_relaxed || sd[t] == INT_MAX) return 0;

   // procura pela menor capacidade restante (gargalo), iterando cada aresta u -> v do caminho aumentativo encontrado
   ll min_c = INT_MAX;
   for (int v = t, u; parent[v].first != -1; v = u) {
      int i; tie(u,i) = parent[v];
      min_c = min(min_c, get<2>(new_adj_list[u][i]));
      // printf("%2d %2d\n", u, v);
   }
   return min_c;
}

/* O((V^2) * (E^2)) - returns {min_cost, max_flow}, where the max flow is bounded by K */
pair<ll,ll> mcmf(int s, int t, ll K) {
   new_adj_list.assign(V, vector<tuple<int,ll,ll,ll>>());
   rev_idx.assign(V, vector<int>());

   // para cada aresta u -(w,c)-> v do grafo original
   for (int u = 0; u < V; u++)
      for (auto adj : adj_list[u]) {
         int v; ll w,c; tie(v,w,c) = adj;

         rev_idx[u].push_back(new_adj_list[v].size());
         rev_idx[v].push_back(new_adj_list[u].size());

         new_adj_list[u].push_back({v, w, c, 0});  // forward edge
         new_adj_list[v].push_back({u, -w, 0, 0}); // backward edge
      }

   ll acc_flow = 0, f;
   ll acc_cost = 0;

   // enquanto existir augmenting path
   while (K > 0 && (f = belmman_ford(s, t))) {
      f = min(f, K);
      acc_flow += f;
      K -= f;

      // atualiza os grafos com o bottleneck, para cada aresta u -> v do caminho aumentativo encontrado
      for (int v = t, u; parent[v].first != -1; v = u) {
         u = parent[v].first;
         int i = parent[v].second;
         int j = rev_idx[u][i];

         get<2>(new_adj_list[u][i]) -= f; // remaining capacity of u -> v
         get<2>(new_adj_list[v][j]) += f; // remaining capacity of v -> u

         get<3>(new_adj_list[u][i]) += f; // flow of u -> v
         get<3>(new_adj_list[v][j]) -= f; // flow of v -> u

         acc_cost += get<1>(new_adj_list[u][i]) * f;
      }
   }
   return {acc_cost, acc_flow};
}

/* e.g */
int main() {
   V = 4;
   adj_list.assign(V, vector<tuple<int,ll,ll>>());

   adj_list[0].push_back({1, 3, 10});
   adj_list[1].push_back({2, 4, 10});
   adj_list[0].push_back({2, 1, 10});
   adj_list[3].push_back({2, 7, 10});
   adj_list[0].push_back({3, 2, 10});

   ll min_cost, max_flow; tie(min_cost, max_flow) = mcmf(0, 2, 20);
   cout << min_cost << " " << max_flow << endl;
   return 0;
}
