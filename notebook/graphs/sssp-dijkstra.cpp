/*
   Single Source Shortest Path (SSSP) - Dijkstra
   
   Motivação: dado um non-negative weighted graph G(V, E), encontre a shortest distance entre um vértice origem s e qualquer outro vértice.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

/* input */
vector<vector<pair<int,ll>>> adj_list; // adj_list[u]: {{v, w}, ...}
int V;

/* output */
vector<ll> sd; // sd[v]: shortest distance from s to v
vector<int> p; // p[v]: parent de v na shortest path tree

/* O((V+E)*log(V)) - returns the distance from s to t */
ll dijkstra(int s, int t) {
   sd.assign(V, INF); p.assign(V, -1);

   priority_queue<pair<ll, int>> pq; // { distância negativa de s até v, v }
   pq.push({-0, s});
   sd[s] = 0;

   while (!pq.empty()) {
      ll dist; int u; tie(dist, u) = pq.top(); dist *= -1; pq.pop();
      if (dist > sd[u]) continue; // vértice já fechado/visitado (lazy deletion)

      if (u == t) return dist;

      // para cada aresta u --w--> v
      for (auto adj : adj_list[u]) {
         int v; ll w; tie(v,w) = adj;

         ll &od = sd[v];    // old distance de v: s -> ... -> v
         ll nd = sd[u] + w; // new distance de v: s -> ... -> u -> v

         // tenta relaxar sd[v]
         if (nd < od) {
            od = nd; 
            pq.push({-nd, v});
            p[v] = u;
         }
      }
   }
}

/* e.g. */
int main() {
   return 0;
}