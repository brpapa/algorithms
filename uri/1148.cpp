/*
   graphs | single-source shortest paths | dijkstra
   problem: countries at war
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 500
#define INF 2147483647
using namespace std;

struct T {
   int id, peso;
};
vector<T> adj[MAX_V]; //adj[i].size(): grau de i
int c[MAX_V]; //c[i]: custo mínimo para ir até o vértice i

void initGrafo() {
   for (int i = 0; i < MAX_V; i++)
      adj[i].clear();
}
void initCustos() {
   for (int i = 0; i < MAX_V; i++)
      c[i] = INF;
}
bool ehAdj(int v, int u) {
   for (int i = 0; i < adj[v].size(); i++)
      if (u == adj[v][i].id)
         return true; //u é adjacente ao v
   return false;
}
void aresta(int a, int b, int w) {
   T aux;
   aux.id = b;  
   aux.peso = w;
   adj[a].push_back(aux); //aresta de a para b com peso w
}

//obs: se há adjacência mútua entre dois vértices considera o peso como nulo (mesmo país)
void dijkstra(int inicio) {
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

         c_aux = c[v] + (ehAdj(u, v)? 0:w);
         if (c_aux < c[u]) { //se o novo custo é melhor
            c[u] = c_aux;
            heap.push(make_pair(-c[u], u));
         }
      }
   }
}

int main() {
   int qteV, qteA; //qte de cidades, qte de acordos
   int v1, v2, w; //x, y, horas
   int qteConsultas;

   while (true) {
      scanf("%d %d", &qteV, &qteA);
      if (qteV == 0 && qteA == 0)
         break;

      initGrafo();
      for (int i = 0; i < qteA; i++) {
         scanf("%d %d %d", &v1, &v2, &w);
         aresta(v1-1, v2-1, w);
      }
      scanf("%d", &qteConsultas);

      while (qteConsultas--) {
         scanf("%d %d", &v1, &v2);
         initCustos();
         //calcula o custo mínimo p todos os vértices a partir de v1-1
         dijkstra(v1-1); 

         if (c[v2-1] != INF)
            printf("%d\n", c[v2-1]);
         else printf("Nao e possivel entregar a carta\n");
      }
      printf("\n");
   }
   return 0;
}