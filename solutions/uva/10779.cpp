/*
   graphs > maximum flow
   difficulty: medium
   date: 10/Aug/2020
   hint: each friend receives 1 flow unit of a sticker and offers a flow of other sticker; Bob also offers, but he receives 1 flow unit of each sticker; maximized it
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<pair<int,ll>>> adj_list; // adj_list[u]: {{v, capacity}, ...}
int V;

/* */
vector<vector<tuple<int,ll,ll>>> new_adj_list; // new_adj_list[u]: {{v, remaining_capacity, flow}, ...}
vector<pair<int,int>> parent; // parent[v]: {u, índice de new_adj_list[u]}
vector<vector<int>> rev_idx;

/* O(V+E) - find the shortest augmenting path (in terms of edges) and returns your bottleneck, or 0, if there is no more an augmenting path */
ll bfs(int s, int t) {
   vector<bool> seen(V, false);
   parent.assign(V, {-1, -1});

   queue<int> q; q.push(s);

   while (!q.empty()) {
      int u = q.front(); q.pop();
      seen[u] = true;

      if (u == t) break;

      // para cada aresta u -c-> v, com c > 0
      for (int i = 0; i < new_adj_list[u].size(); i++) {
         int v; ll c, _; tie(v, c, _) = new_adj_list[u][i];

         if (!seen[v] && c > 0) {
            parent[v] = {u,i};
            q.push(v);
         }
      }
   }

   // t não foi alcançado
   if (parent[t].first == -1) return 0;

   // procura pela menor capacidade restante (gargalo), iterando cada aresta u -> v do caminho aumentativo encontrado
   ll min_c = INT_MAX;
   for (int v = t, u; parent[v].first != -1; v = u) {
      u = parent[v].first;
      int i = parent[v].second;
      min_c = min(min_c, get<1>(new_adj_list[u][i]));
   }
   return min_c;
}

/* O(V*E*E) - returns the max flow */
ll edmonds_karp(int s, int t) {
   new_adj_list.assign(V, vector<tuple<int,ll,ll>>());
   rev_idx.assign(V, vector<int>());

   // para cada aresta u -c-> v do grafo original
   for (int u = 0; u < V; u++)
      for (auto adj : adj_list[u]) {
         int v, c; tie(v, c) = adj;

         rev_idx[u].push_back(new_adj_list[v].size());
         rev_idx[v].push_back(new_adj_list[u].size());

         new_adj_list[u].push_back({v, c, 0}); // forward edge
         new_adj_list[v].push_back({u, 0, 0}); // backward edge
      }

   ll acc_flow = 0, f;

   // enquanto existir augmenting path
   while ((f = bfs(s, t))) {
      acc_flow += f;

      // atualiza os grafos com o min_c, para cada aresta u -> v do caminho aumentativo encontrado
      for (int v = t, u; parent[v].first != -1; v = u) {
         u = parent[v].first;
         int i = parent[v].second;
         int j = rev_idx[u][i];

         get<1>(new_adj_list[u][i]) -= f; // remaining capacity of u -> v
         get<1>(new_adj_list[v][j]) += f; // remaining capacity of v -> u

         get<2>(new_adj_list[u][i]) += f; // flow of u -> v
         get<2>(new_adj_list[v][j]) -= f; // flow of v -> u
      }
   }
   return acc_flow;
}

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      int N, M; cin >> N >> M;
      V = M+N+1;
      adj_list.assign(V, vector<pair<int,ll>>());

      // vértice 0: oferta do Bob
      // vértices [1..M]: stickers
      // vértice M+1: demanda do Bob
      // vértices [M+2, V-1]: amigos de Bob

      vector<ll> qty(30, 0); int k; cin >> k; while (k--) { int m; cin >> m; qty[m]++; }
      for (int m = 1; m <= M; m++) {
         adj_list[m].push_back({M+1, 1});
         if (qty[m] > 0) adj_list[0].push_back({m, qty[m]});
      }

      for (int n = M+2; n < V; n++) {
         vector<int> qty(30, 0); int k; cin >> k; while (k--) { int m; cin >> m; qty[m]++; }
         for (int m = 1; m <= M; m++) {
            if (qty[m] == 0) adj_list[m].push_back({n, 1});
            else adj_list[n].push_back({m, qty[m]-1});
         }
      }
      printf("Case #%d: %ld\n", t++, edmonds_karp(0, M+1));
   }
	return 0;
}
