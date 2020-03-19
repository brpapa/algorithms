/*
   ad-hoc
   difficulty: none
   date: none
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n, m, p, quant;
   vector<int> vet, ord;

   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> m;
      for (int j = 0; j < m; j++) {
         cin >> p;
         vet.push_back(p);
         ord.push_back(p);
      }
      quant = 0;
      sort(ord.begin(), ord.end(), greater<int>());

      for (int j = 0; j < vet.size(); j++) {
         if (ord[j] == vet[j])
            quant++;
      }
      cout << quant << endl;
      vet.clear();
      ord.clear();
   }
   return 0;
}