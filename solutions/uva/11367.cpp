/*
   graphs > shortest path > single-source > weighted graph
   difficulty: hard
   date: 25/Feb/2020 
   hint: find the shortest path on state-space graph, where each vertex represent a city and a level of car fuel
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int INF = 1 << 30;

struct Tadj {
   int id, w;
   Tadj(int id, int w) : id(id), w(w) {}
};
vector<vector<Tadj>> adjList;
int V;

vector<int> fp; // fuel prices

int dijk(int s, int e, int C) {
   // source vertex s, goal vertex e, car fuel capacity C

   // sd[v][c]: menor distância do vértice (s, 0) até (v, c)
   vector<vector<int>> sd(V, vector<int>(C+1, INF));
   sd[s][0] = 0;

   priority_queue<tuple<int, int, int>> pq; // distance from (s,0), id, car fuel level c
   pq.push(make_tuple(-sd[s][0], s, 0));

   while (!pq.empty()) {
      int u_d = -get<0>(pq.top()), u_id = get<1>(pq.top()), u_c = get<2>(pq.top());
      pq.pop();

      if (u_d > sd[u_id][u_c]) continue;

      // para cada aresta (u_id, u_c) --v.w--> v.id
      for (Tadj v : adjList[u_id]) {
         if (u_c-v.w >= 0) {
            // (u_id, u_c) --0--> (v.id, u_c-v.w)
            int nd = sd[u_id][u_c] + 0;
            int &od = sd[v.id][u_c-v.w];

            if (nd < od) {
               od = nd;
               pq.push(make_tuple(-nd, v.id, u_c-v.w));
            }
         }
      }

      if (u_c+1 <= C) {
         // (u_id, u_c) --(fp[u])--> (u_id, u_c+1)
         int nd = sd[u_id][u_c] + fp[u_id];
         int &od = sd[u_id][u_c+1];

         if (nd < od) {
            od = nd;
            pq.push(make_tuple(-nd, u_id, u_c+1));
         }
      }
   }
   return sd[e][0];
}

int main() {
   int E; cin >> V >> E;
   adjList.resize(V);
   fp.resize(V); for (int &p : fp) cin >> p;

   while (E--) {
      int u, v, w; cin >> u >> v >> w;
      adjList[u].push_back(Tadj(v, w));
      adjList[v].push_back(Tadj(u, w));
   }

   int Q; cin >> Q;
   while (Q--) {
      int C, s, e; cin >> C >> s >> e;

      int ans = dijk(s, e, C);
      if (ans == INF) cout << "impossible" << endl;
      else cout << ans << endl;
   }
   return 0;
}
