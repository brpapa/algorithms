/* 
   Dado um grafo G(V, E) e um vértice inicial s, uma BFS percorre por largura (nível por nível).
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<int>> adj_list; int V;

/* O(V+E) */
void bfs(int s) {
   vector<bool> seen(V, false);
   vector<int> depth(V);      // depth[v]: nível do vértice v em relação à s
   vector<int> parent(V, -1); // parent[v]: parent of v

	queue<int> q; q.push(s);
	depth[s] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		seen[u] = true;

      // processa vértice u
		cout << u << endl; 

		for (int v : adj_list[u])
			if (!seen[v]) {
				depth[v] = depth[u]+1;
				parent[v] = u;
				q.push(v);
			}
	}
}

/* e.g. */
int main() {
   adj_list.assign(V, vector<int>());

   bfs(0);
}
