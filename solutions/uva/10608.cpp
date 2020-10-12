/*
   data structures > union-find disjoint sets (UFDS)
   difficulty: easy
   date: 20/Jul/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

struct UFDS {
   vector<int> p;    // p[n]: pai do elemento n
   vector<int> size; // size[n]: tamanho do conjunto identificado por n
   int count;        // quantidade de conjuntos

   UFDS(int N) {
      p.resize(N);
      size.assign(N, 1);
      count = N;
      
      // inicialmente, o elemento identificador de cada conjunto é ele próprio
      for (int n = 0; n < N; n++) p[n] = n;
   }

   // retorna o elemento identificador do conjunto de n
   int findSet(int n) {
      if (p[n] == n) return n;

      // comprime o caminho, durante a busca
      return p[n] = findSet(p[n]); 
   }
	
   // os conjuntos de n e de m são os mesmos?
   bool isSameSet(int n, int m) {
      return findSet(n) == findSet(m);
   }

	// conecta os conjuntos de n e de m
   void unionSet(int n, int m) {
      int id_n = findSet(n);
      int id_m = findSet(m);

      // union by size: anexa a menor árvore (em profundidade) à maior árvore
      if (!isSameSet(id_n, id_m)) {
         if (size[id_n] > size[id_m])
            swap(id_n, id_m);

         p[id_n] = id_m;
         size[id_m] += size[id_n];

         count--;
      }
   }

   int getSetSize(int n) {
      return size[findSet(n)];
   }
};

int main() {
   int T; cin >> T;
   while (T--) {
      int N, M; cin >> N >> M;
      UFDS uf(N);

      int ans = 1;
      while (M--) {
         int a, b; cin >> a >> b; a--; b--;
         uf.unionSet(a, b);

         ans = max(ans, uf.getSetSize(a));
         ans = max(ans, uf.getSetSize(b));
      }

      cout << ans << endl;
   }
	return 0;
}
