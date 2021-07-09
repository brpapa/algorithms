/* 
   Tarjan - SCCs

   Motivação: dado um directed graph G(V, E), encontre todos os seus SCCs. Um SCC é um ciclo independentes em G, onde sempre há pelo menos um caminho entre quaisquer dois vértices dele.

   ---
   Exemplo em ./notebook/assets/scc.png
   Se contraírmos cada SCC em um único vértice temos um DAG.
   Um SCC é uma sub-árvore da árvore gerada pela DFS em G.

   ---
   https://youtu.be/TyWtx7q2D7Y
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
vector<vector<int>> adj_list;  int V;

// UNVISITED: vértice ainda não visitado
// VISITING: vertíce visitado, mas ainda visitando seus adjacentes (do CC atual)
// VISITED: vértice já teve todos seus adjacentes visitados e já faz parte de um SCC
enum { UNVISITED, VISITING, VISITED };
vector<int> state;
vector<int> order;  // order[v] = indicador da ordem de visitação do vértice pela DFS
vector<int> low;    // low[v] = menor order alcançável a partir de v (inclusive ele mesmo) na árvore gerada pela DFS
stack<int> s;       // vértices atuais que estão sendo VISITING (na ordem de visitação)
int count_order, count_scc;

/* O(V+E) */
void dfs(int u) {
	low[u] = order[u] = count_order++;
	state[u] = VISITING; s.push(u);

	for (int v : adj_list[u]) {  // para cada aresta u -> v
		if (state[v] == UNVISITED)
			dfs(v);
		
		// callback propagation of DFS
		
		if (state[v] == VISITING) // v está na pilha atual
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == order[u]) {   // u é a raiz de um SCC e já teve todos seus adjacentes visitados
		printf("SCC %d:", count_scc++);
		
		int v;
		do {
			v = s.top(); s.pop();
			printf(" %d", v);
			state[v] = VISITED;
		} while (v != u);
		printf("\n");
	}
}

int main() {
   int V = 8;
   adj_list.assign(V, vector<int>());
   adj_list[0].push_back(1);
   adj_list[1].push_back(3);
   adj_list[3].push_back(2);
   adj_list[2].push_back(1);
   adj_list[3].push_back(4);
   adj_list[4].push_back(5);
   adj_list[5].push_back(7);
   adj_list[7].push_back(6);
   adj_list[6].push_back(4);

   count_order = count_scc = 0;
   order.resize(V); low.resize(V); state.assign(V, UNVISITED);

   for (int v = 0; v < V; v++)
      if (state[v] == UNVISITED)
         dfs(v);
   return 0;
}