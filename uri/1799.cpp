/*
   graphs > traversal > breadth-first search (BFS)
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> gr[4000];
int qteV;

map<string, int> id;

//retorna true, se u é um dos filhos de v
bool ehAdjacente(int v, int u) {
   for (int i = 0; i < gr[v].size(); i++)
      if (u == gr[v][i])
         return true;
   return false;
}
//insere aresta ao grafo não direcionado
void aresta(int a, int b) {
   if (!ehAdjacente(a, b)) gr[a].push_back(b);
   if (!ehAdjacente(b, a)) gr[b].push_back(a);
}
//mapeia cada string como um número id e o retorna
int str2id(string str, int &v) {
   if (!id.count(str))
      id[str] = v++;
   return id[str];
}

int bfs(int init, int dest) {
   vector<bool> visitado(qteV, false);
   vector<int> nivel(qteV);
   queue<int> fila;

   fila.push(init);
   visitado[init] = true;
   nivel[init] = 0;

   while (!fila.empty()) {
      int v = fila.front(); //pai
      fila.pop();

      if (v == dest)
         return nivel[v];

      for (int i = 0; i < gr[v].size(); i++) {
         int u = gr[v][i]; //filho

         if (!visitado[u]) {
            nivel[u] = nivel[v]+1;
            visitado[u] = true;
            fila.push(u);
         }
      }
   }
   return 0;
}

int main() {
   int ans = 0, qteA;
   int v = 0; //contador do número atual de vértices
   string pt1, pt2;

   scanf("%d %d", &qteV, &qteA);
   for(int i = 0; i < qteA; i++) {
      cin >> pt1 >> pt2;
      aresta(str2id(pt1, v), str2id(pt2, v));
   }
   // for (map<string, int>::iterator it = id.begin(); it != id.end(); it++)
   //    cout << it->second << " " << it->first << endl;

   ans += bfs(id["*"], id["Entrada"]); //ida
   ans += bfs(id["*"], id["Saida"]);   //volta
   cout << ans << endl;
   return 0;
}