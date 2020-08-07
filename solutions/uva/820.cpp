/*
   graphs > maximum flow
   difficulty: easy
   date: 06/Aug/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list; // adj_list[u]: {{v, w}, ...}
int V;

vector<vector<pair<int,int>>> remaining; // remaining[u]: {{v, current remaining capacity}, ...}
vector<vector<pair<int,int>>> flow;      // flow[u]: {{v, current flow}, ...}
vector<pair<int,int>> bfs_parent;        // bfs_parent[u]: {pai de u, índice em remaining[u]}
vector<vector<int>> rev;

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
   rev.assign(V, vector<int>());

   // para cada aresta u -w-> v do grafo original
   for (int u = 0; u < V; u++)
      for (auto adj : adj_list[u]) {
         int v = adj.first, w = adj.second;

         rev[u].push_back(remaining[v].size());
         rev[v].push_back(remaining[u].size());

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
         int j = rev[u][i];

         remaining[u][i].second -= new_flow; // weight of u -> v
         remaining[v][j].second += new_flow; // weight of v -> u

         flow[u][i].second += new_flow; // weight of u -> v
         flow[v][j].second -= new_flow; // weight of v -> u
      }
   }
   return acc_flow;
}

int main() {
   int count = 1;
   while (cin >> V && V) {
      adj_list.assign(V, vector<pair<int, int>>());
      int s, t; cin >> s >> t; s--; t--;
      int E; cin >> E;
      while (E--) {
         int u, v, w; cin >> u >> v >> w; u--; v--;
         adj_list[u].push_back({v, w});
         adj_list[v].push_back({u, w});
      }
      printf("Network %d\n", count++);
      printf("The bandwidth is %d.\n\n", edmonds_karp(s, t));
   }
   return 0;
}