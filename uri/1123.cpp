/*
   graphs | shortest path | dijkstra
   difficulty: medium
   problem: route change
   date: 22/May/2019
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 250
#define INF 2147483647
using namespace std;

struct Tadj {
   int id, w;
};
struct Theap {
   int id, c;

   Theap(int id, int c) {
      this->id = id;
      this->c = c;
   }
   bool operator<(const Theap &p) const {
      return this->c < p.c;
   }
};

vector<Tadj> adj[MAX_V];
int c[MAX_V];
int R; // cidades da rota: 0 a R-1

void init() {
   for (int v = 0; v < MAX_V; v++) {
      adj[v].clear();
      c[v] = INF;
   }
}

void insertEdge(int a, int b, int w) {
   Tadj v, u;
   v.id = a;
   u.id = b;
   v.w = u.w = w;
   
   //a é da rota
   if (a < R) {
      if (b == a+1 && b < R) //b é o seguinte imediato e da rota
         adj[a].push_back(u); 
      else if (b == a-1 || b >= R) //b é o anterior imediato da rota ou não é da rota
         adj[b].push_back(v);
   }
   //a não é da rota e b é da rota
   else if (a >= R && b < R)
      adj[a].push_back(u);
   //ambos não pertencem à rota
   else if (a >= R && b >= R) {
      adj[a].push_back(u);
      adj[b].push_back(v);
   }
}

void dijkstra(int vInit) {
   priority_queue<Theap> heap;

   c[vInit] = 0;
   heap.push(Theap(vInit, c[vInit]));

   while (!heap.empty()) {
      int v = heap.top().id; // vértice de menor custo
      heap.pop();            // fecha vértice v

      for (int i = 0; i < adj[v].size(); i++) {
         int u = adj[v][i].id;
         int w = adj[v][i].w;

         int c_new = c[v] + w;
         if (c_new < c[u]) {
            c[u] = c_new;
            heap.push(Theap(u, c[u]));            
         }
      }
   }
}

int main() {
   int V, E; // cidades, estradas
   int v1, v2, w;
   int x; // cidade onde veiculo foi consertado

   while (true) {
      scanf("%d %d %d %d", &V, &E, &R, &x);
      if (V == 0 && E == 0 && R == 0 && x == 0)
         break;

      init();
      for (int e = 0; e < E; e++) {
         scanf("%d %d %d", &v1, &v2, &w);
         insertEdge(v1, v2, w); //grafo orientado
      }
      dijkstra(x);
      printf("%d\n", c[R-1]);
   }
   return 0;
}