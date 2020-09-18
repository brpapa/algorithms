/*
   graphs > minimum spanning tree (MST) > minimum spanning subgraph
   difficulty: medium
   date: 03/Jun/2020
   problem: given an implicit complete graph and some edges, compute the cost of the minimum spanning subgraph
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
struct UFDS {
   vector<int> p; // p[i]: pai do item i

   UFDS(int N) {
      p.resize(N);
      for (int i = 0; i < N; i++) p[i] = i; 
   }

   int findSet(int i) {
      if (p[i] == i) return i;
      return p[i] = findSet(p[i]);
   }

   bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
   }

   void unionSet(int i, int j) {
      int setI = findSet(i);
      int setJ = findSet(j);
      if (!isSameSet(setI, setJ)) p[setI] = setJ;
   }
};

typedef pair<int, int> ii;

struct Tedge {
   int u, v; double w;
   Tedge() {}
   Tedge(int u, int v, double w) : u(u), v(v), w(w) {}
   bool operator<(const Tedge& p) const { return w < p.w; }
};

ii coords[777];
double dist(int u, int v) {
   ii cu = coords[u], cv = coords[v];
   int dx = abs(cu.first - cv.first);
   int dy = abs(cu.second - cv.second);
   return sqrt(dx*dx + dy*dy);
}

int main() {
   int V;
   while (cin >> V) {
      for (int v = 0; v < V; v++) {
         int x, y; cin >> x >> y; coords[v] = ii(x, y);
      }

      vector<Tedge> edgeList; // arestas do grafo completo, priorizando as mais leves
      for (int u = 0; u < V; u++)
         for (int v = u+1; v < V; v++)
            edgeList.push_back(Tedge(u, v, dist(u, v)));
      
      sort(edgeList.begin(), edgeList.end());

      UFDS uf(V); // conjuntos de componentes conectados
      int E; cin >> E;
      while (E--) {
         int u, v; cin >> u >> v; u--; v--;
         uf.unionSet(u, v);
      }

      double ans = 0;
      for (Tedge e : edgeList) {
         if (!uf.isSameSet(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            ans += e.w;
         }
      }
      printf("%.2f\n", ans);
   }
   return 0;
}
