/*
   Motivação: dado um non-negative weighted graph G(V, E), encontre a shortest distance entre um vértice origem s e qualquer outro vértice.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
vector<vector<pair<int,int>>> adj_list; // adj_list[u]: {{v, w}, ...}
int V;

/* output */
vector<int> sd; // sd[v]: shortest distance de s à v
vector<int> p;  // p[v]: parent de v na shortest path tree

/* O((V+E)*log(V)) */
void dijkstra(int s) {
   sd.assign(V, INF); p.assign(V, -1);

   priority_queue<pair<int, int>> pq; // {distância negativa atual de s, u}
   pq.push(make_pair(-0, s));
   sd[s] = 0;

   while (!pq.empty()) {
      int dist = -pq.top().first, u = pq.top().second;
      pq.pop(); // "fecha" o vértice de menor distance

      if (dist > sd[u])
         continue; // vértice já fechado/visitado (lazy deletion)

      // para cada aresta u --w--> v
      for (auto adj : adj_list[u]) {
         int v = adj.first, w = adj.second;

         int &od = sd[v];       // old distance de s até v
         int nd = sd[u] + w; // new distance de s até v

         // tenta relaxar sd[v]
         if (nd < od) {
            od = nd; 
            pq.push(make_pair(-nd, v));
            p[v] = u;
         }
      }
   }
}

int main() {
   dijkstra(0);
   return 0;
}