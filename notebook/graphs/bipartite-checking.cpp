/*
   Bipartite checking

   Motivação: dado um connected and undirected graph G(V, E), determine se ele é bipartido, ou seja, se pode ser "pintado" em apenas duas cores sem que vértices adjacentes tenham a mesma cor.

   Bipartite graph: the set of vertices V can be partitioned into two disjoint sets LV and RV, and, for all edges (l,r) of E, l is in LV (left vertices) and r is in RV (right vertices).

   Obs: the graph is 2-colourable (bipartite) if there is no cycle with an odd length.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<int>> adj_list; int V;

/* O(V+E) - return true if the connected component is bipartite */
bool bfs(int s) {
   enum { WHITE, BLACK, WITHOUT_COLOR };

   vector<int> state(V, WITHOUT_COLOR); state[s] = WHITE;
	queue<int> q; q.push(s);
	bool isBipartite = true;

	while (!q.empty() && isBipartite) {
		int u = q.front(); q.pop();

		for (int v : adj_list[u]) {
			if (state[v] == WITHOUT_COLOR) {  // não visitado
				state[v] = (state[u]+1) % 2;   // BLACK ou WHITE
				q.push(v);
			}
			else if (state[v] == state[u]) {  // conflito de cor
				isBipartite = false;
			}
		}
	}
	return isBipartite;
}

/* e.g */
int main() {
   cout << bfs(0) << endl;
}