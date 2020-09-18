/*
   miscellaneous > union-find disjoint sets (UFDS)
   difficulty: easy
   date: 20/Jul/2020
   by: @brpapa
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

   // retorna o elemento identificador do conjunto de n
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

      // union by size: conecta a menor árvore (em profundidade) à maior árvore
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

double dist(pair<double, double> p, pair<double, double> q) {
   double dx = p.first-q.first;
   double dy = p.second-q.second;
   return sqrt(dx*dx + dy*dy);
}

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      int N; double d; cin >> N >> d;

      UFDS uf(N);

      vector<pair<double,double>> stars(N);
      for (auto &star : stars) 
         cin >> star.first >> star.second;

      for (int i = 0; i < N; i++)
         for (int j = i+1; j < N; j++) {
            if (dist(stars[i], stars[j]) <= d)
               uf.unionSet(i, j);
         }
      
      printf("Case %d: %d\n", t++, uf.count());
   }
	return 0;
}
