/*
   Maximum Cardinality Bipartite Matching (MCBM) - Emparelhamento Máximo

   Motivação: dado um unweighted, directed and bipartite graph G(V,E), encontre o maior número de matchings possíveis, ou seja, o maior número de arestas l -> r, sendo que l faz parte do conjunto LV e r de RV, e nenhum vértice tenha grau maior que 1.

   Perfect matching: todos os vértices do grafo fazem parte de um match.

   Max Independent Set: max(|RV|, |LV|) = |V| - MCBM

   Obs: o problema também pode ser reduzido ao problema de max flow, ao montar o flow graph da seguinte forma: s -1-> l, l -1-> r, l -1-> t.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
int V = 4, LV = 2; 
vector<vector<int>> adj_list = { 
   {2, 3},
   {2},
   {},
   {}
}; // apenas com arestas l -> r, onde 0 <= l < LV e LV <= r < V, é suficiente

vector<int> match; // match[r]: vértice l já combinado com r
vector<bool> seen;

/* O(E) - return true if an augmenting path is found */
bool has_aug(int l) {
  if (seen[l]) return 0;
  seen[l] = true;

  for (int r : adj_list[l]) {
      if (match[r] == -1 || has_aug(match[r])) {
         match[r] = l;
         return true;
      } 
  }
  return false;
}

/* O(V*E) - return the max qty of matchings */
int mcbm() {
   int ans = 0;
   match.assign(V, -1);
   for (int l = 0; l < LV; l++) {
      seen.assign(LV, false);
      ans += has_aug(l);
   }
  return ans;
}

/* e.g */
int main() {
  cout << mcbm() << endl;
}
