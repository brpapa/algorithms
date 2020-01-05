/*
   graphs > depth first search (DFS)
   problem: coloring a tree
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

vector<int> arv[MAX];
int corDesejada[MAX], qte;

//recebe o nó e a sua cor
int dfs(int no, int cor) {
   int qte = 0;

   if (cor != corDesejada[no]) {
      cor = corDesejada[no];
      qte = 1;
   }
   //a cor propaga para cada filho do nó
   for (int i = 0; i < arv[no].size(); i++)
      qte += dfs(arv[no][i], cor);

   return qte;
}

int main() {
   int n, p;
   scanf("%d", &n);
   for (int f = 2; f <= n; f++) {
      scanf("%d", &p);
      arv[p].push_back(f);
   }
   for (int i = 1; i <= n; i++)
      scanf("%d", &corDesejada[i]);

   printf("%d\n", dfs(1, 0));
   return 0;
}