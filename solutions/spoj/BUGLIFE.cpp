/*
   graphs > specials > bipartite > bipartite checking
   difficulty: easy
   date: 19/Aug/2020
   hint: check all connect components
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list; int V;

enum { WHITE, BLACK, WITHOUT_COLOR };
vector<int> state;

bool bfs(int s) {
   state[s] = WHITE;
	queue<int> q; q.push(s);
	bool isBipartite = true;

	while (!q.empty() && isBipartite) {
		int u = q.front(); q.pop();

		for (int v : adj_list[u]) {
			if (state[v] == WITHOUT_COLOR) {
				state[v] = (state[u]+1) % 2;
				q.push(v);
			}
			else if (state[v] == state[u]) {  // conflito de cor
				isBipartite = false;
			}
		}
	}
	return isBipartite;
}

int main() {
   int T, t = 1; cin >> T;
   while (T--) {
      int E; cin >> V >> E;
      adj_list.assign(V, vector<int>());
      while (E--) {
         int u, v; cin >> u >> v; u--; v--;
         adj_list[u].push_back(v);
         adj_list[v].push_back(u);
      }

      bool isBipartite = true;
      state.assign(V, WITHOUT_COLOR);
      for (int root = 0; root < V; root++)
         if (state[root] == WITHOUT_COLOR)
            if (!bfs(root)) {
               isBipartite = false;
            }
      
      printf("Scenario #%d:\n", t++);
      if (!isBipartite) cout << "Suspicious bugs found!\n";
      else cout << "No suspicious bugs found!\n";
   }
	return 0;
}
