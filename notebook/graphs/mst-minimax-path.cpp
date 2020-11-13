/*
   Motivation: given a connected, undirected and weighted graph G(V, E), find the maximum weight of the minimum path from s to t.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* input */
int V;
vector<tuple<ll,int,int>> edge_list; // {{w, u, v}, ...}, arestas u -w-> v

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

/* O(E*log(V)) - returns the max_w of the minimum path from s to t, or -1 if not exists path from s to t */
ll kruskal(int s, int t) {
	ufds sets(V);
	sort(edge_list.begin(), edge_list.end());

   // para cada aresta u -w-> v, priorizando as de menor w
	for (auto edge: edge_list) {
      int u, v; ll w; tie(w,u,v) = edge;

      // evita ciclos
		if (!sets.is_same_set(u, v)) { 
         sets.union_sets(u, v);
         // se s e t já se conectaram, as próximas arestas da MST não farão parte do caminho s -> t
         if (sets.is_same_set(s, t))
            return w;
		}
   }
   return -1;
}

int main() {
   V = 7;
   edge_list.push_back({50,0,1});
   edge_list.push_back({90,1,4});
   edge_list.push_back({120,1,3});
   edge_list.push_back({40,4,6});
   edge_list.push_back({70,3,6});
   edge_list.push_back({80,3,5});
   edge_list.push_back({140,5,6});
   edge_list.push_back({50,2,5});
   edge_list.push_back({60,0,2});

   cout << kruskal(0, 6) << endl; // 80, da aresta 3-5
   return 0;
}
