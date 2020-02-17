/*
   graphs > shortest path > single-source > dijkstra
   difficulty: medium
   problem: route change
   date: 22/May/2019
   author: @brnpapa
*/
#include <iostream>
#include <queue>
#include <vector>
#define MAX_V 250
#define INF 2147483647
using namespace std;

struct Tadj {
   int id, w;
   Tadj(int id, int w) : id(id), w(w) {}
};
vector<Tadj> adjList[MAX_V];

struct Theap {
   int id, c;

   Theap(int id, int c) : id(id), c(c) {}
   bool operator<(const Theap &p) const {
      return this->c < p.c;
   }
};
int c[MAX_V];
int R; // cidades da rota: 0 a R-1

void insertEdge(int a, int b, int w) {
   Tadj v(a, w), u(b, w);

   //a é da rota
   if (a < R) {
      if (b == a + 1 && b < R) //b é o seguinte imediato e da rota
         adjList[a].push_back(u);
      else if (b == a - 1 || b >= R) //b é o anterior imediato da rota ou não é da rota
         adjList[b].push_back(v);
   }
   //a não é da rota e b é da rota
   else if (a >= R && b < R)
      adjList[a].push_back(u);
   //ambos não pertencem à rota
   else if (a >= R && b >= R) {
      adjList[a].push_back(u);
      adjList[b].push_back(v);
   }
}

void dijkstra(int init_v) {
   priority_queue<Theap> heap;

   c[init_v] = 0;
   heap.push(Theap(init_v, c[init_v]));

   while (!heap.empty()) {
      int v = heap.top().id; // vértice de menor custo
      heap.pop();            // fecha vértice v

      for (Tadj u : adjList[v]) {
         int c_new = c[v] + u.w;

         if (c_new < c[u.id]) {
            c[u.id] = c_new;
            heap.push(Theap(u.id, c[u.id]));
         }
      }
   }
}

int main() {
   int V, E; // cidades, estradas
   int x;    // cidade onde veiculo foi consertado

   while (true) {
      scanf("%d %d %d %d", &V, &E, &R, &x);
      if (V == 0 && E == 0 && R == 0 && x == 0)
         break;

      // init
      for (int v = 0; v < MAX_V; v++) {
         adjList[v].clear();
         c[v] = INF;
      }

      int v1, v2, w;
      while (E--) {
         scanf("%d %d %d", &v1, &v2, &w);
         insertEdge(v1, v2, w); //grafo orientado
      }
      dijkstra(x);
      printf("%d\n", c[R - 1]);
   }
   return 0;
}