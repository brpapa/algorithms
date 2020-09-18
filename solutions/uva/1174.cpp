/*
   graphs > minimum spanning tree (MST)
   difficulty: easy
   date: 03/Jun/2020
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

map<string, int> city2id;

struct Tedge {
   int u, v, w;
   Tedge() {}
   Tedge(int u, int v, int w) : u(u), v(v), w(w) {}
   bool operator<(const Tedge& p) const { return w < p.w; }
};

int main() {
   int t = 0, T; cin >> T;
   while (T--) {
      if (t++ > 0) cout << endl;

      int V, E; cin >> V >> E;
      vector<Tedge> edgeList(E); city2id.clear();
      V = 0;
      for (Tedge &e : edgeList) {
         string u, v; cin >> u >> v; int w; cin >> w;

         if (!city2id.count(u)) city2id[u] = V++;
         if (!city2id.count(v)) city2id[v] = V++;
         e = Tedge(city2id[u], city2id[v], w);
      }

      UFDS uf(V);
      sort(edgeList.begin(), edgeList.end());
      
      int ans = 0;
      for (Tedge e: edgeList)
         if (!uf.isSameSet(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            ans += e.w;
         }
      cout << ans << endl;
   }
   return 0;
}
