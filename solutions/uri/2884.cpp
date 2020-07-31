/*
   ad-hoc
   difficulty: easy
   date: 28/Feb/2019 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

void ativaInterruptor(vector<bool> &lamp, vector<int> inte) {
   for (int i = 1; i <= inte[0]; i++)
      lamp[inte[i] - 1] = !lamp[inte[i] - 1];
}
bool todasEstaoApagadas(vector<bool> lamp) {
   for (int i = 0; i < lamp.size(); i++)
      if (lamp[i] == true)
         return false;
   return true;
}

int main() {
   int n, m, l, k, aux;
   //le os dados de entrada
   cin >> n >> m >> l;
   vector<bool> lamp(m, false);
   for (int i = 0; i < l; i++) {
      cin >> aux;
      lamp[aux - 1] = true;
   }
   vector<vector<int>> inte(n);
   for (int i = 0; i < n; i++) {
      cin >> k;
      inte[i].push_back(k);
      for (int j = 1; j <= k; j++) {
         cin >> aux;
         inte[i].push_back(aux);
      }
   }
   //ativa os i interruptores 2 vezes
   int cont = 0;
   for (int vez = 0; vez < 2; vez++) {
      for (int i = 0; i < n && !todasEstaoApagadas(lamp); i++) {
         ativaInterruptor(lamp, inte[i]);
         cont++;
      }
   }
   printf("%d\n", todasEstaoApagadas(lamp) ? cont : -1);
   return 0;
}