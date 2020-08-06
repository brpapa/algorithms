/*
   Network flow: max flow

   Motivação: dado um flow graph G(V, E), quanto de "fluxo", no máximo, pode estar passando from the source s to the sink t, ao fornecer uma fonte infinita desse "fluxo" em s.
   (imagine uma água fluindo em uma rede de canos)

   A flow graph is a connected, weighted and directed graph where each edge (arc) has a certain capacity and can receive a less or equal amount of flow.

   The remaining capacity of an edge is equals to capacity minus current flow

   Forward edges: (given by the original graph, it has a flow and a capacity)
      - increasing the flow by the bottleneck of the augmenting path
   Backward edges: (it has a negative flow (opposite of the matching forward edge) and capacity 0, that is, a positive remaining capacity value)
      - decreasing the flow by the bottleneck of the augmenting path

   Augmenting path: path of forward or backward edges e, from s to t, with remaining capacity > 0, where that minimum remaining capacity is the bottleneck
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<pair<int,int>>> adj_list; // adj_list[u]: {{v, w}, ...}
int V;

/* */
vector<vector<pair<int,int>>> remaining; // remaining[u]: {{v, current remaining capacity}, ...}
vector<vector<pair<int,int>>> flow;      // flow[u]: {{v, current flow}, ...}
vector<pair<int,int>> bfs_parent;        // bfs_parent[v]: {u, índice em remaining[u]}
vector<vector<int>> rev_idx;

// O(V+E) - find an augmenting path and returns your bottleneck flow, or 0, if there is no more an augmenting path
int bfs(int s, int t) {
   vector<bool> seen(V, false);
   bfs_parent.assign(V, {-1, -1});

   queue<int> q; q.push(s);

   while (!q.empty()) {
      int u = q.front(); q.pop();
      seen[u] = true;

      if (u == t) break;

      // para cada aresta u -w-> v
      for (int i = 0; i < remaining[u].size(); i++) {
         int v = remaining[u][i].first;
         int w = remaining[u][i].second;

         if (!seen[v] && w > 0) {
            bfs_parent[v] = {u,i};
            q.push(v);
         }
      }
   }

   // t não foi alcançado
   if (bfs_parent[t].first == -1) return 0;

   // procura pelo o gargalo, iterando cada aresta u -> v do caminho encontrado
   int bottleneck = INT_MAX;
   for (int v = t, u; bfs_parent[v].first != -1; v = u) {
      u = bfs_parent[v].first;
      int i = bfs_parent[v].second;
      bottleneck = min(bottleneck, remaining[u][i].second);
   }
   return bottleneck;
}

/* O(V*E*E) - returns the max flow */
int edmonds_karp(int s, int t) {
   remaining.assign(V, vector<pair<int,int>>());
   flow.assign(V, vector<pair<int,int>>());
   rev_idx.assign(V, vector<int>());

   // para cada aresta u -w-> v do grafo original
   for (int u = 0; u < V; u++)
      for (auto adj : adj_list[u]) {
         int v = adj.first, w = adj.second;

         rev_idx[u].push_back(remaining[v].size());
         rev_idx[v].push_back(remaining[u].size());

         remaining[u].push_back({v, w}); // forward edge
         remaining[v].push_back({u, 0}); // backward edge
         flow[u].push_back({v, 0}); // forward edge
         flow[v].push_back({u, 0}); // backward edge
      }

   int acc_flow = 0, new_flow;

   // enquanto existir augmenting path
   while ((new_flow = bfs(s, t))) {
      acc_flow += new_flow;

      // atualiza os grafos com o bottleneck, para cada aresta u -> v do caminho encontrado pela bfs
      for (int v = t, u; bfs_parent[v].first != -1; v = u) {
         u = bfs_parent[v].first;
         int i = bfs_parent[v].second;
         int j = rev_idx[u][i];

         remaining[u][i].second -= new_flow; // weight of u -> v
         remaining[v][j].second += new_flow; // weight of v -> u

         flow[u][i].second += new_flow; // weight of u -> v
         flow[v][j].second -= new_flow; // weight of v -> u
      }
   }
   return acc_flow;
}

/* e.g */
int main() {
   V = 6;
   adj_list.assign(V, vector<pair<int,int>>());

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
