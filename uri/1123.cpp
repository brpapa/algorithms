/*
   graph | minimum path | dijkstra
   problem: route change
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 250
#define INF 2147483647
using namespace std;

struct T {
   int id, peso;
};
vector<T> adj[MAX_V]; //adj[i].size(): grau de i
int c[MAX_V];
int qteRota; //0 a qteRota-1: cidades da rota

void init() {
   for (int i = 0; i < MAX_V; i++) {
      adj[i].clear();
      c[i] = INF;
   }
}
bool ehAdj(int v, int u) {
   for (int i = 0; i < adj[v].size(); i++)
      if (u == adj[v][i].id)
         return true; //u é adjacente ao v
   return false;
}
void aresta(int a, int b, int w) {
   T v, u;
   v.id = a;
   u.id = b;
   v.peso = u.peso = w;
   
   //a é da rota
   if (a < qteRota) {
      if (b == a+1 && b < qteRota) //b é o seguinte imediato e da rota
         adj[a].push_back(u); 
      else if (b == a-1 || b >= qteRota) //b é o anterior imediato da rota ou não é da rota
         adj[b].push_back(v);
   }
   //a não é da rota e b é da rota
   else if (a >= qteRota && b < qteRota)
      adj[a].push_back(u);
   //ambos não pertencem à rota
   else if (a >= qteRota && b >= qteRota) {
      adj[a].push_back(u);
      adj[b].push_back(v);
   }
}

void dijkstra(int inicio) {
   priority_queue<pair<int, int> > heap; //-c[id], id

   c[inicio] = 0;
   heap.push(make_pair(c[inicio], inicio));

   int v, u, w, c_aux;
   while (!heap.empty()) {
      v = heap.top().second; //vértice de custo mínimo
      heap.pop();            //fecha o vértice v

      for (int i = 0; i < adj[v].size(); i++) {
         u = adj[v][i].id;
         w = adj[v][i].peso;

         c_aux = c[v] + w;
         if (c_aux < c[u]) {
            c[u] = c_aux;
            heap.push(make_pair(-c[u], u));            
         }
      }
   }
}

int main() {
   int qteV, qteA; //qte de cidades, qte de estradas
   int x, c1, c2, w; //x: cidade onde veiculo foi consertado

   while(true) {
      scanf("%d %d %d %d", &qteV, &qteA, &qteRota, &x);
      if (qteV == 0 && qteA == 0 && qteRota == 0 && x == 0)
         break;

      init();
      for (int i = 0; i < qteA; i++) {
         scanf("%d %d %d", &c1, &c2, &w);
         aresta(c1, c2, w); //grafo orientado
      }
      dijkstra(x);
      printf("%d\n", c[qteRota-1]);
   }
   return 0;
}