/*
   graphs > minimum spanning tree (MST)
   difficulty: easy
   date: 03/Jun/2020
   by: @brnpapa
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

map<string, int> station2id;

struct Tedge {
   int u, v, w;
   Tedge() {}
   Tedge(int u, int v, int w) : u(u), v(v), w(w) {}
   bool operator<(const Tedge& p) const { return w < p.w; }
};

int main() {
   int V, E;
   while (cin >> V >> E && (V || E)) {
      for (int v = 0; v < V; v++) {
         string station; cin >> station; station2id[station] = v;
      }

      vector<Tedge> edgeList(E);
      for (Tedge &e : edgeList) {
         string u, v; cin >> u >> v; int w; cin >> w;
         e = Tedge(station2id[u], station2id[v], w);
      }
      string station; cin >> station;
      int s = station2id[station];

      UFDS uf(V);
      sort(edgeList.begin(), edgeList.end());
      
      int ans = 0;
      for (Tedge e: edgeList)
         if (!uf.isSameSet(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            ans += e.w;
         }
      
      bool allConnected = true;
      for (int v = 0; v < V; v++) if (!uf.isSameSet(s, v)) allConnected = false;

      if (!allConnected) cout << "Impossible" << endl;
      else cout << ans << endl;
   }
   return 0;
}
