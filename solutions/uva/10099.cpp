/*
   graphs > minimum spanning tree (MST) > minimax path
   difficulty: medium
   date: 08/Sep/2020
   problem: maximin path; find the minimum cost of the maximum path from s to t
   hint: apply kruskal to get the maximum spanning tree, but stop it when s and t connect
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int V;
vector<tuple<ll,int,int>> edge_list; // {{w, u, v}, ...}, arestas u -w-> v

class ufds {
 private:
   vector<int> parent; // parent[n] = pai do elemento n
   vector<int> size;   // size[n] = tamanho do conjunto identificado por n
   int qty_disjoint_sets;

 public:
   ufds() {}
   ufds(int N) {
      parent.resize(N);
      size.assign(N, 1);
      qty_disjoint_sets = N;
      
      // inicialmente, há N conjuntos disjuntos
      for (int n = 0; n < N; n++) parent[n] = n;
   }

   /* O(1) - retorna a raiz do conjunto de n */
   int find_set(int n) {
      if (parent[n] == n) return n;
      return parent[n] = find_set(parent[n]); // path compression
   }
	
   /* O(1) - os conjuntos de n e de m são os mesmos? */
   bool is_same_set(int n, int m) {
      return find_set(n) == find_set(m);
   }

	/* O(1) - conecta os conjuntos de n e de m */
   void union_sets(int n, int m) {
      int n_id = find_set(n);
      int m_id = find_set(m);

      // union by size: conecta a menor árvore à maior árvore
      if (!is_same_set(n_id, m_id)) {
         if (size[n_id] > size[m_id])
            swap(n_id, m_id);

         parent[n_id] = m_id;
         size[m_id] += size[n_id];

         qty_disjoint_sets--;
      }
   }

   /* O(1) - tamanho do conjunto de n */
   int set_size(int n) {
      return size[find_set(n)];
   }

   /* O(1) - quantidade de conjuntos disjuntos */
   int count() {
      return qty_disjoint_sets;
   }
};

/* O(E*log(V)) - retorna o peso da aresta mais leve na "MST" que conecta s e t */
ll kruskal(int s, int t) {
	ufds sets(V);
	sort(edge_list.rbegin(), edge_list.rend()); // prioriza arestas com maior w

   ll min_w;
	for (auto edge: edge_list) {
      int u, v; ll w; tie(w,u,v) = edge;

      // evita ciclos
		if (!sets.is_same_set(u, v)) { 
         sets.union_sets(u, v);
         if (sets.is_same_set(s, t)) {
            min_w = w;
            break;
         }
		}
   }
   return min_w;
}

int main() {
   int E, test = 1;
   while (cin >> V >> E && (V || E)) {
      edge_list.clear();
      while (E--) {
         int u,v; ll w; cin >> u >> v >> w; u--; v--; w--;
         edge_list.push_back({w,u,v});
      }

      int s,t; ll people; cin >> s >> t >> people; s--; t--;

      ll min_w = kruskal(s,t);
      ll ans = ceil((double)people/min_w);

      cout << "Scenario #" << (test++) << endl;
      cout << "Minimum Number of Trips = " << ans << endl << endl;
   }
   return 0;
}
