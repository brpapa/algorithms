/*
   graph | breadth first search (BFS)
   problem: lost elf
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, level[101];
vector<int> gr[101]; // grafo não direcionado com n*m vértices (salões)
bool visited[101];

void insertEdge(int v, int u) {
   gr[v].push_back(u);
   gr[u].push_back(v);
}

void bfs(int root) {
   queue<int> q;
   q.push(root);
   visited[root] = true;
   level[root] = 0;

   int v, u;
   while (!q.empty()) {
      v = q.front();
      q.pop();

      for (int i = 0; i < gr[v].size(); i++) {
         u = gr[v][i];

         if (!visited[u]) {
            visited[u] = true; // na fila
            q.push(u);
            level[u] = level[v]+1;
         }
      }
   }
}

int main() {
   cin >> n >> m;

   bool isWall[101];
   memset(isWall, false, sizeof(isWall));
   memset(visited, false, sizeof(visited));

   int c, v, vStart, vEnd = n*m;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
         cin >> c;
         v = i*m + j;

         if (c == 2) {
            isWall[v] = true;
            continue; 
         }
         if (j != 0 && !isWall[v-1])
            insertEdge(v, v-1); // v à esq
         if (i != 0 && !isWall[v-m])
            insertEdge(v, v-m); // v acima

         if (c == 0) // v tem saída
            insertEdge(v, vEnd);
         else if (c == 3)
            vStart = v;
      }

   bfs(vStart);
   cout << level[vEnd]-1 << endl;

   return 0;
}