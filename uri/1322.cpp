/*
   graphs > traversal > depth-first search (DFS)
   difficulty: none
   problem: kids' wishes
   date: none
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#define MAX 2*100000 //qte máxima de desejos ao dobro, já que, no pior dos casos, cada desejo será de uma criança distinta
using namespace std;

vector<int> grafo[MAX];
int grau[MAX], pre[MAX], qteVisitados;
bool temConflito, visitado[MAX];
unordered_map<int, int> id;

void init() {
   id.clear();
   temConflito = false;
   for (int i = 0; i < MAX; i++) {
      grafo[i].clear();
      grau[i] = 0;
      pre[i] = -1; //vetor de predecessores
      visitado[i] = false;
   }
}
bool ehAdjacente(int v, int u) {
   for (int i = 0; i < grau[v]; i++)
      if (u == grafo[v][i])
         return true; //u é um dos filhos de v
   return false;
}
void aresta(int a, int b) {
   //grafo não direcionado
   if (!ehAdjacente(a, b)) {
      grafo[a].push_back(b);
      grafo[b].push_back(a);
      if ((++grau[a]) > 2 || (++grau[b]) > 2)
         temConflito = true;
   }
}
//mapeia cada crianca como um número id e o retorna
int crianca2id(int cr, int &qteV) {
   if (!id.count(cr))
      id[cr] = qteV++;
   return id[cr];
}
//verifica se o grafo tem ciclo
bool dfs(int init) {
   int v, u;
   bool ciclo = false;

   stack<int> p;
   p.push(init);
   visitado[init] = true;
   qteVisitados++;

   while (!p.empty()) {
      v = p.top();
      p.pop();

      for (int i = 0; i < grau[v]; i++) {
         u = grafo[v][i];

         if (!visitado[u]) {
            pre[u] = v; //v prescede u
            p.push(u);
            visitado[u] = true;
            qteVisitados++;
         }
         //achou o início e u não prescede v
         else if (u != pre[v]) 
            ciclo = true;
      }
   }
   return ciclo;
}

int main() {
   int qteCriancas, qteDesejos, a, b, qteV;
   bool temCiclo;
   
   while (true) {
      scanf("%d %d", &qteCriancas, &qteDesejos);
      if (qteCriancas == 0 && qteDesejos == 0)
         return 0;

      init();
      qteV = 0;
      for (int i = 0; i < qteDesejos; i++) {
         scanf("%d %d", &a, &b);
         aresta(crianca2id(a, qteV), crianca2id(b, qteV));
      }
      // for (unordered_map<int, int>::iterator it = id.begin(); it != id.end(); it++)
      //    cout << it->first << " -> " << it->second << endl;
      if (temConflito)
         printf("N\n");
      else {
         temCiclo = false;
         for (int i = 0; i < qteV && !temCiclo; i++)
            if (!visitado[i]) {
               qteVisitados = 0;
               temCiclo = dfs(i) || temCiclo;
            }

         if (!temCiclo)
            printf("Y\n");
         else if (qteCriancas > qteVisitados) 
            printf("N\n"); //tem ciclo e sobrou alguem
         else 
            printf("Y\n"); //tem ciclo e não sobrou ninguem
      }
   }
   return 0;
}