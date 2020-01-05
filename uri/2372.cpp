/*
   graphs > shortest paths > all-pairs > floyd-warshall
   difficulty: easy
   problem: meeting
   date: 25/Oct/2019
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#define INF 214748364
#define MAX_V 110
using namespace std;

int V, E;
int c[MAX_V][MAX_V]; // custo da aresta (i, j)

void init() {
   for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++)
         c[i][j] = INF;
      c[i][i] = 0;
   }
}

void floyd() {
   for (int k = 0; k < V; k++)
      for (int i = 0; i < V; i++)
         for (int j = 0; j < V; j++)
            c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}

int main() {
   cin >> V >> E;
   init();

   int v1, v2, w;
   for (int e = 0; e < E; e++) {
      cin >> v1 >> v2 >> w;
      c[v1][v2] = w;
      c[v2][v1] = w;
   }
   floyd();

   int minn = INF;
   for (int i = 0; i < V; i++) {
      int maxx = -INF;
      for (int j = 0; j < V; j++)
         maxx = max(maxx, c[i][j]);
      minn = min(minn, maxx);
   }
   cout << minn << endl;
   return 0;
}