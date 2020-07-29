/*
   miscellaneous > union-find disjoint sets (UFDS)
   difficulty: easy
   date: 20/Jul/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

class UFDS {
 private:
   vector<int> p;    // p[n]: pai do elemento n
   vector<int> size; // size[n]: tamanho do conjunto identificado por n
   int qtyDisjointSets;

 public:
   UFDS() {}

   // elementos n (0 <= n < N)
   UFDS(int N) {
      p.resize(N);
      size.assign(N, 1);
      qtyDisjointSets = N;
      
      // inicialmente, há N conjuntos disjuntos
      for (int n = 0; n < N; n++) p[n] = n;
   }

   // retorna a raiz do conjunto de n
   int findSet(int n) {
      if (p[n] == n) return n;

      // path compression durante a busca
      return p[n] = findSet(p[n]); 
   }
	
   // os conjuntos de n e de m são os mesmos?
   bool isSameSet(int n, int m) {
      return findSet(n) == findSet(m);
   }

	// conecta os conjuntos de n e de m
   void unionSet(int n, int m) {
      int nId = findSet(n);
      int mId = findSet(m);

      // union by size: conecta a menor árvore à maior árvore
      if (!isSameSet(nId, mId)) {
         if (size[nId] > size[mId])
            swap(nId, mId);

         p[nId] = mId;
         size[mId] += size[nId];

         qtyDisjointSets--;
      }
   }

   // retorna o tamanho do conjunto de n
   int sizeOfSet(int n) {
      return size[findSet(n)];
   }

   // retorna a quantidade de conjuntos disjuntos
   int count() {
      return qtyDisjointSets;
   }
};

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      UFDS uf(N+1);
      for (int n = 1; n <= N; n++) {
         int p; cin >> p;
         uf.unionSet(p, n);
      }
      for (int n = 1; n < N; n++) cout << uf.sizeOfSet(n) << " ";
      cout << uf.sizeOfSet(N) << endl;
   }
	return 0;
}
