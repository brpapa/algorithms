#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/*
   Motivação: dado um non-negative weighted graph G(V, E), encontre a shortest distance entre um vértice origem s e qualquer outro vértice.
*/

/* inputs */
struct Tadj {
   int id, w;
};
vector<vector<Tadj>> adj_list;
int V;

/* outputs */
vector<int> sd; // sd[v]: shortest distance de s à v
vector<int> p;  // p[v]: parent de v na shortest path tree

/* O((V+E)*log(V)) */
void dijkstra(int s) {
   sd.assign(V, INF); p.assign(V, -1);

   priority_queue<pair<int, int>> pq; // (distância atual de s (negativa), v)
   pq.push(make_pair(-0, s));
   sd[s] = 0;

   while (!pq.empty()) {
      int u_d = -pq.top().first, u_id = pq.top().second;
      pq.pop(); // "fecha" o vértice de menor distance

      if (u_d > sd[u_id])
         continue; // vértice já fechado/visitado (lazy deletion)

      // para cada aresta u_id --v.w--> v.id
      for (Tadj v : adj_list[u_id]) {
         int &od = sd[v.id];      // old distance de s até v.id
         int nd = sd[u_id] + v.w; // new distance de s até v.id

         // tenta relaxar sd[v.id]
         if (nd < od) {
            od = nd; 
            pq.push(make_pair(-nd, v.id));
            p[v.id] = u_id;
         }
      }
   }
}

int main() {
   dijkstra(0);
   return 0;
}