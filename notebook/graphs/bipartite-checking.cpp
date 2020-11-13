/*
   Bipartite checking

   Motivação: dado um connected and undirected graph G(V, E), determine se ele é bipartido.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<int>> adj_list; int V;

/* O(V+E) - returns true if the connected component is bipartite */
bool bfs(int s) {
   enum { WHITE, BLACK, WITHOUT_COLOR };

   vector<int> state(V, WITHOUT_COLOR); state[s] = WHITE;
	queue<int> q; q.push(s);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : adj_list[u]) {
			if (state[v] == WITHOUT_COLOR) {  // não visitado
				state[v] = (state[u]+1) % 2;   // BLACK ou WHITE
				q.push(v);
			}
			else if (state[v] == state[u])    // conflito de cor
				return false;
		}
	}
	return true;
}

int main() {
   cout << bfs(0) << endl;
}
