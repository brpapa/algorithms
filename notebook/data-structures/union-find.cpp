#include <bits/stdc++.h>
using namespace std;

/*
   Cada conjunto é representado por uma árvore, onde o elemento raiz é o identificador único de todo o conjunto.

   Um elemento n é a raiz de sua árvore se parent[n] == n
*/

class UFDS {
 private:
   vector<int> parent; // parent[n]: pai do elemento n
   vector<int> size;   // size[n]: tamanho do conjunto identificado por n
   int qtyDisjointSets;

 public:
   UFDS() {}

   // elementos n (0 <= n < N)
   UFDS(int N) {
      parent.resize(N);
      size.assign(N, 1);
      qtyDisjointSets = N;
      
      // inicialmente, há N conjuntos disjuntos
      for (int n = 0; n < N; n++) parent[n] = n;
   }

   // retorna a raiz do conjunto de n
   int find_set(int n) {
      if (parent[n] == n) return n;

      // path compression durante a busca
      return parent[n] = find_set(parent[n]); 
   }
	
   // os conjuntos de n e de m são os mesmos?
   bool is_same_set(int n, int m) {
      return find_set(n) == find_set(m);
   }

	// conecta os conjuntos de n e de m
   void union_sets(int n, int m) {
      int nId = find_set(n);
      int mId = find_set(m);

      // union by size: conecta a menor árvore à maior árvore
      if (!is_same_set(nId, mId)) {
         if (size[nId] > size[mId])
            swap(nId, mId);

         parent[nId] = mId;
         size[mId] += size[nId];

         qtyDisjointSets--;
      }
   }

   // retorna o tamanho do conjunto de n
   int set_size(int n) {
      return size[find_set(n)];
   }

   // retorna a quantidade de conjuntos disjuntos
   int count() {
      return qtyDisjointSets;
   }
};

/* e.g */
int main() {
   UFDS sets(5);
   sets.union_sets(0, 1);
   sets.union_sets(3, 4);
   sets.union_sets(0, 4);

   cout << sets.is_same_set(0, 4) << endl;
}