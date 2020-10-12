/*
   data structures > union-find disjoint sets (UFDS)
   difficulty: easy
   date: 31/Aug/2020
   hint: 2 ^ (sum of (size of set - 1), for each disjoint set)
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

class ufds {
 private:
   vector<int> size;   // size[n]: tamanho do conjunto identificado por n
   int qty_disjoint_sets;

 public:
   vector<int> parent; // parent[n]: pai do elemento n

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

int main() {
   int N, M; cin >> N >> M;

   ufds sets(N);
   while (M--) {
      int x,y; cin>>x>>y; x--; y--;
      sets.union_sets(x,y);
   }

   ll sum_sizes = 0;
   for (int n = 0; n < N; n++)
      if (sets.parent[n] == n)
         sum_sizes += sets.set_size(n)-1;

   cout << (ll)pow(2, sum_sizes) << endl;
   return 0;
}

// 1 - 2 - 3 - 4
// 5 - 6 - 7
// 8 - 9

// 2*2*2*2*2*2
// 2^6 = 2^(1+2+3)