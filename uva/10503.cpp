/*
   graphs > traversal > depth-first search (DFS)
   difficulty: medium
   date: 14/Apr/2020
   problem: given domino pieces, check if it is possible to arrive at a target piece from an initial piece using N intermediate pieces (possibly rotating them)
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // node
const int UNVISITED = -1;
const int VISITED = 0;

int N;
map<pii, int> state;
pii target;
bool hasSolution;

void dfs(pii u, int lvl, bool rotate) {
   // rotate: peça u foi colocada invertida?

   if (hasSolution) return;
   state[u] = VISITED;

   if (u == target && !rotate && lvl == N+2) {
      hasSolution = true;
      return;
   }

   int last = rotate? u.first : u.second;

   // para cada nó ligável à last
   for (auto s : state) {
      pii v = s.first;
      if (state[v] == UNVISITED) {
         if (last == v.first)  dfs(v, lvl+1, 0);
         if (last == v.second) dfs(v, lvl+1, 1);
      }
   }

   state[u] = UNVISITED;
}

int main() {
   while (cin >> N && N) {
      int M; cin >> M;
      pii init; cin >> init.first >> init.second;
      cin >> target.first >> target.second;

      hasSolution = 0;
      state.clear();
      state[target] = UNVISITED;

      while (M--) {
         pii node; cin >> node.first >> node.second;
         state[node] = UNVISITED;
      }

      dfs(init, 1, 0);
      cout << (hasSolution? "YES":"NO") << endl;
   }
   return 0;
}
