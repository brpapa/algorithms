/*
   graphs > shortest path > single-source > weighted graph
   difficulty: medium
   date: 08/Sep/2020
   problem: almost shortest path
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

vector<vector<pair<int,ll>>> adj_list; // adj_list[u] = {{v, w}, ...}
int V;

vector<pair<int,int>> p;

/* O((V+E)*log(V)) */
ll dijkstra(int s, int t, bool first_run) {
   vector<ll> sd(V, INF); 
   p.assign(V, {-1,-1});

   priority_queue<pair<ll, int>> pq; // { distância negativa de s até v, v }
   pq.push({-0, s});
   sd[s] = 0;

   vector<pair<int,int>> pt;

   while (!pq.empty()) {
      ll dist = -pq.top().first; int u = pq.top().second; pq.pop();
      if (dist > sd[u]) continue;

      if (u == t && !first_run) return dist;

      // para cada aresta u --w--> v
      for (int i = 0; i < adj_list[u].size(); i++) {
         int v; ll w; tie(v,w) = adj_list[u][i];

         ll &od = sd[v];    // old distance de v: s -> ... -> v
         ll nd = sd[u] + w; // new distance de v: s -> ... -> u -> v

         // tenta relaxar sd[v]
         if (nd < od) {
            od = nd; 
            pq.push({-nd, v});
            p[v] = {u,i};

            if (v == t) pt = {p[v]};
         }
         else if (v == t && nd == od)
            pt.push_back({u,i});
      }
   }

   // invalida os melhores caminhos
   if (first_run) {
      for (auto parent : pt) {
         int v, i; tie(v, i) = parent;

         adj_list[v][i].second = INF;

         for (int u; p[v].first != -1; v = u) {
            tie(u, i) = p[v];
            adj_list[u][i].second = INF;
         }
      }
   }

   return INF;
}

int main() {
   int E;
   while (cin >> V >> E && (V || E)) {
      adj_list.assign(V, vector<pair<int,ll>>());
      int s, t; cin >> s >> t;
      while (E--) {
         int u, v; ll w; cin >> u >> v >> w;
         adj_list[u].push_back({v,w});
      }
      
      dijkstra(s, t, true);
      ll ans = dijkstra(s, t, false);
      ans = ans != INF? ans: -1;
      cout << ans << endl;
   }

   return 0;
}