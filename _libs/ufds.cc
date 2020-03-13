#include <iostream>
#include <vector>
using namespace std;

struct UFDS {
   vector<int> p; // p[i]: pai do item i

   UFDS(int I) {
      p.assign(I, 0);
      // cada item como um conjunto disjunto do outro
      for (int i = 0; i < I; i++) p[i] = i; 
   }

   // retorna o item identificador do conjunto em que i pertence
   int findSet(int i) {
      if (p[i] == i) return i;
      return p[i] = findSet(p[i]); // otimiza comprimindo o caminho
   }

   bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
   }

   void unionSet(int i, int j) {
      int setI = findSet(i);
      int setJ = findSet(j);

      //! é possível otimizar
      if (!isSameSet(setI, setJ)) p[setI] = setJ;
   }
};

int main() {

}