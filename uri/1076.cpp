//graphs: basic
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

vector<int> adj[MAX]; //vector de vértices adjacentes ao vértice i

//verifica se b é adjacente à a
bool ehAdjacente(int a, int b) 
{
   for (int i = 0; i < adj[a].size(); i++)
      if (b == adj[a][i])
         return true;
   return false;
}
void addAresta(int a, int b)
{
   adj[a].push_back(b);
   adj[b].push_back(a);
}

int main()
{
   int t, n, qteV, qteA, v, a;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d", &n); //nó inicial e final
      scanf("%d %d", &qteV, &qteA);

      for (int i = 0; i < qteV; i++) 
         adj[i].clear();

      int qtePassosIda = 0;
      for (int i = 0; i < qteA; i++) 
      {
         scanf("%d %d", &v, &a);
         if (ehAdjacente(v, a))
            continue;

         //adiciona aresta ao grafo não direcionado
         addAresta(v, a);
         qtePassosIda++;
      }
      printf("%d\n", qtePassosIda*2);
   }
   return 0;
}