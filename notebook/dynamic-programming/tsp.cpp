/*
   Traveling Salesman Problem (TSP) - (caixeiro viajante)

   Motivação: dado V cidades e suas distâncias entre si (grafo completo), encontre o custo mínimo de um caminho que passe por todas as cidades apenas uma vez, começando e terminando em uma cidade s.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
vector<vector<int>> adj_mat; // adj_mat[u][v]: distancia entre as cidades u e v
int V;
int s; // note que qualquer s levará sempre à mesma resposta

vector<vector<int>> memo;
/* O(V * 2^V) * O(V) = O(V^2 * 2^V) */
int dp(int u, int mask) {
   // cidade atual u, conjunto de cidades visitadas mask (inclui-se u)

   if ((1 << V)-1 == mask)  // todas cidades foram visitadas
      return adj_mat[u][s]; // volta

   int &ans = memo[u][mask];
   if (ans != -1) return ans;

   ans = INF;
   for (int v = 0; v < V; v++)
      if (!(mask & (1 << v))) // para cada cidade ainda não visitada
         ans = min(ans, adj_mat[u][v] + dp(v, mask | (1 << v)));
   return ans;
}

/* e.g. */
int main() {
   V = 4;
   adj_mat.assign(V, vector<int>(V, 0));
   adj_mat = {
      { 0, 20, 42, 35},
      {20,  0, 30, 34},
      {42, 30,  0, 12},
      {35, 34, 12,  0}
   };

   memo.assign(V, vector<int>(1 << V, -1));
   s = 0;
   cout << dp(s, 1 << s) << endl; 
   // 97, pois é o custo do caminho 0 -> 1 -> 2 -> 3 -> 0
}

// Não há um ganho absurdo se comparado à força bruta em O((V-1)!), mas ainda é melhor. Resolve problemas com 11 ≤ V ≤ 16.