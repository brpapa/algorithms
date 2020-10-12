/*
   Maximum flow

   Statement: given a connected, weighted and (un)directed graph where every edge has a capacity, and two vertices source ‘s’ and sink ‘t’, find the maximum possible flow from s to t with following constraints:
      - flow on an edge doesn’t exceed the given capacity of the edge.
      - incoming flow is equal to outgoing flow for every vertex, except s and t.

   ---

   The remaining capacity of an edge is equals to capacity minus current flow.

   Forward edges: (given by the original graph, it has a flow and a capacity)
      - increasing the flow by the min_c of the augmenting path
   Backward edges: (it has a negative flow (opposite of the matching forward edge) and capacity 0, that is, a positive remaining capacity value)
      - decreasing the flow by the min_c of the augmenting path

   Augmenting path: path of forward or backward edges e, from s to t, with remaining capacity > 0, where that minimum remaining capacity is the min_c
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
vector<vector<pair<int,ll>>> adj_list; // adj_list[u]: {{v, capacity}, ...}
int V;

/* */
vector<vector<tuple<int,ll,ll>>> new_adj_list; // new_adj_list[u]: {{v, remaining_capacity, flow}, ...}
vector<pair<int,int>> parent; // parent[v]: {u, índice em new_adj_list[u]}
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
      int i; tie(u, i) = parent[v];
      min_c = min(min_c, get<1>(new_adj_list[u][i]));
   }
   return min_c;
}

/* O(V*E*E) - returns the max flow from s to t */
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

/* e.g */
int main() {
   V = 6;
   adj_list.assign(V, vector<pair<int,ll>>());

   adj_list[0].push_back({1, 10});
   adj_list[0].push_back({2, 10});
   adj_list[2].push_back({4, 15});
   adj_list[4].push_back({1, 6});
   adj_list[1].push_back({3, 25});
   adj_list[3].push_back({5, 10});
   adj_list[4].push_back({5, 10});

   cout << edmonds_karp(0, 3) << endl;
   return 0;
}

// https://youtu.be/RppuJYwlcI8?list=PLDV1Zeh2NRsDj3NzHbbFIC58etjZhiGcG
