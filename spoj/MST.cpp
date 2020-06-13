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

typedef long long ll;

struct Tedge {
   int u, v; ll w;
   Tedge() {}
   Tedge(int u, int v, ll w) : u(u), v(v), w(w) {}
   bool operator<(const Tedge& p) const { return w < p.w; }
};

int main() {
    int V, E; cin >> V >> E;
    vector<Tedge> edgeList(E);
    for (Tedge &e : edgeList) {
        int u, v; cin >> u >> v; u--; v--;
        ll w; cin >> w;

        e = Tedge(u, v, w);
    }

    UFDS uf(V);
    sort(edgeList.begin(), edgeList.end());
    
    ll ans = 0;
    for (Tedge e: edgeList)
        if (!uf.isSameSet(e.u, e.v)) {
          uf.unionSet(e.u, e.v);
          ans += e.w;
        }
    cout << ans << endl;
   return 0;
}
