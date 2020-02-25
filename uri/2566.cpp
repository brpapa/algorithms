/*
   graphs > shortest path > dijkstra
   problem: trip to bh
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 100
#define INF 2147483647
using namespace std;

struct T {
   int id, peso;
};
int c[MAX_V];

void initGrafo(vector<T> adj[]) {
   for (int i = 0; i < MAX_V; i++)
      adj[i].clear();
}
void initCustos() {
   for (int i = 0; i < MAX_V; i++)
      c[i] = INF;
}
bool ehAdj(int v, int u, vector<T> adj[]) {
   for (int i = 0; i < adj[v].size(); i++)
      if (u == adj[v][i].id)
         return true; //u é adjacente ao v
   return false;
}
void aresta(int a, int b, int w, vector<T> adj[]) {
   T aux;
   aux.id = b;  
   aux.peso = w;
   adj[a].push_back(aux); //aresta de a para b com peso w
}

void dijkstra(int inicio, vector<T> adj[MAX_V]) {
   initCustos();
   //prioridade para os menores custos (first sempre negativo)
   priority_queue< pair<int, int> > heap; 
   heap.push(make_pair(c[inicio]=0, inicio));
   
   int v, u, w, c_aux;
   while (!heap.empty()) {
      v = heap.top().second; //vértice de custo mínimo
      heap.pop(); //fecha o vértice v

      for (int i = 0; i < adj[v].size(); i++) {
         u = adj[v][i].id;
         w = adj[v][i].peso; //peso entre v e u

         c_aux = c[v] + w;
         if (c_aux < c[u]) { //se o novo custo é melhor
            c[u] = c_aux;
            heap.push(make_pair(-c[u], u));
         }
      }
   }
}

int main() {
   vector<T> adj0[MAX_V], adj1[MAX_V]; //onibus, aviao
   int qteV, qteA; //qte de cidades, qte de trechos
   int a, b, t, r, custoOnibus, custoAviao;

   while (scanf("%d %d", &qteV, &qteA) != EOF) {
      initGrafo(adj0);
      initGrafo(adj1);
      for (int i = 0; i < qteA; i++) {
         scanf("%d %d %d %d", &a, &b, &t, &r);
         (t == 0)? aresta(a-1, b-1, r, adj0):aresta(a-1, b-1, r, adj1);
      }
      dijkstra(0, adj0);
      custoOnibus = c[qteV-1];
      dijkstra(0, adj1);
      custoAviao = c[qteV-1];
      printf("%d\n", min(custoOnibus, custoAviao));
   }
   return 0;
}