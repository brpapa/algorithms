/*
   Minimum Spanning Tree (MST) - Kruskal

   Motivação: dado um connected, undirected and weighted graph G(V, E), encontre uma árvore T(V, V-1) contida em G, tal que a soma dos pesos das arestas seja a menor possível e conecte todos os vértices de G.

   ---
   Kruskal busca pelas arestas mais leves gulosamente. É mais intuitivo para recuperar as arestas da MST.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
int V;
vector<tuple<ll,int,int>> edge_list; // {{w, u, v}, ...}, arestas u -w-> v

/* output */
vector<tuple<int,int,ll>> mst_edges; // {{u, v, w}, ...}

class ufds {
 private:
   vector<int> parent; // parent[n]: pai do elemento n
   vector<int> size;   // size[n]: tamanho do conjunto identificado por n
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

/* O(E*log(V)) - returns the MST cost */
ll kruskal() {
	mst_edges.clear();
	ufds sets(V); // conjuntos de componentes conectados
	sort(edge_list.begin(), edge_list.end());

	ll mst_cost = 0;	

   // para cada aresta u -w-> v, priorizando as de menor w
	for (auto edge: edge_list) {
      int u, v; ll w; tie(w,u,v) = edge;

      // evita ciclos
		if (!sets.is_same_set(u, v)) { 
         sets.union_sets(u, v);
         mst_cost += w;
         mst_edges.push_back({u,v,w});
		}
   }
	return mst_cost;
}

/* e.g. */
int main() {
   V = 5;
   edge_list.push_back({1, 0, 1});
   edge_list.push_back({2, 0, 2});
   edge_list.push_back({5, 1, 3});
   edge_list.push_back({9, 2, 4});
   edge_list.push_back({1, 3, 4});
   edge_list.push_back({3, 2, 4});
   cout << kruskal() << endl;
   return 0;
}