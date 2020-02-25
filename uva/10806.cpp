/*
   graphs > shortest path > dijkstra
   difficulty: medium
   problem: dijkstra, dijkstra
   date: 23/Feb/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_V 110
#define INF (1 << 30)
using namespace std;

int V;
struct Tadj {
   int id, w;
   Tadj() {}
   Tadj(int id, int w) : id(id), w(w) {}
};
vector<Tadj> adjList[MAX_V];

struct Tpq {
   int id, dist;
   Tpq(int id, int dist) : id(id), dist(dist) {}
   bool operator<(const Tpq &p) const { return dist < p.dist; }
};
bool usedEdge[MAX_V][MAX_V];

vector<int> shortestDist, parent;
void dijk(int s) {
   shortestDist.assign(V, INF); shortestDist[0] = 0; parent.assign(V, -1);
   priority_queue<Tpq> pq; pq.push(Tpq(s, 0));

   while (!pq.empty()) {
      Tpq v = pq.top(); pq.pop();
      if (v.dist > shortestDist[v.id]) continue;

      // para cada aresta v.id --u.w--> u.id
      for (Tadj u : adjList[v.id]) {
         if (usedEdge[v.id][u.id]) continue;
         
         int newDist = shortestDist[v.id] + u.w;
         if (newDist < shortestDist[u.id]) {
            shortestDist[u.id] = newDist;
            pq.push(Tpq(u.id, shortestDist[u.id]));
            parent[u.id] = v.id;
         }
      }
   }
}

int main() {
   while (cin >> V && V) {
      for (int v = 0; v < V; v++) adjList[v].clear(); 
      
      int E; cin >> E;
      while (E--) {
         int v, u, w; cin >> v >> u >> w; v--; u--;
         adjList[v].push_back(Tadj(u, w));
         adjList[u].push_back(Tadj(v, w));
      }

      memset(usedEdge, 0, sizeof usedEdge);

      dijk(0); int he = shortestDist[V-1];

      for (int v = V-1; v != 0; v = parent[v]) {
         usedEdge[parent[v]][v] = 1;
         for (Tadj &u : adjList[v])
            if (u.id == parent[v])
               u.w *= -1;
      }

      dijk(0); int you = shortestDist[V-1];
      if (you == INF) { cout << "Back to jail" << endl; continue; }

      cout << he+you << endl;
   }
   return 0;
}

// edge case: ans = 22
/*
6
8
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
1 3 10
2 6 10
0
*/