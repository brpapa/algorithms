/*
   Motivação: dado um undirected graph G(V, E) e usando a sua DFS spanning tree, classifique as suas arestas em:
      - tree edge: aresta da árvore gerada pela DFS.
      - bi-directional edge: aresta que forma um ciclo direto (oposto da tree edge).
      - back edge: aresta que forma um ciclo não-direto.
      - forward/cross edge: oposto da back edge
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
vector<vector<int>> adj_list; int V;

// UNVISITED: vértice não visitado
// VISITING: vértice visitado, mas ainda visitando seus adjacentes (do CC atual)
// VISITED: vértice visitado e completo (todos seus adjacentes já foram visitados)
enum { UNVISITED, VISITING, VISITED };
vector<int> state;
vector<int> parent;

/* O(V+E) */
void dfs(int u) {
	state[u] = VISITING;

	// para cada aresta u -> v
	for (int v : adj_list[u]) {
      // VISITING -> UNVISITED
		if (state[v] == UNVISITED) {      
			printf("%d -> %d: tree edge\n", u, v);
			parent[v] = u;
			dfs(v);
		}
      // callback propagation of DFS
      
      // VISITING -> VISITING
		else if (state[v] == VISITING) {  
			if (v == parent[u])
            printf("%d -> %d: bi-directional edge\n", u, v);
			else               
            printf("%d -> %d: back edge\n", u, v);
		}
      // VISITING -> VISITED
		else if (state[v] == VISITED) {   
         printf("%d -> %d: forward/cross edge\n", u, v);
		}
	}

	state[u] = VISITED;
}


int main() {
   /*
      0 - 1 - 2 - 3 - 4
          |_______|
   */
   V = 5;
   adj_list.assign(V, vector<int>());
   adj_list[0].push_back(1); adj_list[1].push_back(0);
   adj_list[1].push_back(2); adj_list[2].push_back(1);
   adj_list[2].push_back(3); adj_list[3].push_back(2);
   adj_list[3].push_back(4); adj_list[4].push_back(3);
   adj_list[3].push_back(1); adj_list[1].push_back(3);

   state.assign(V, UNVISITED); parent.assign(V, -1);
   for (int cc = 0, u = 0; u < V; u++)
      if (state[u] == UNVISITED) {
         parent[u] = -1;
         printf("%d-th connected component:\n", ++cc);
         dfs(u);
      }
   return 0;
}