/*
   ad-hoc
   difficulty: none
   problem: phase
   date: none
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n, k, aux;
   cin >> n >> k;
   vector<int> pts(n);
   for (int i = 0; i < n; i++) {
      cin >> aux;
      pts.push_back(aux);
   }
   sort(pts.begin(), pts.end(), greater<int>());

   int minComp = k;
   while (pts[minComp-1] == pts[minComp] && minComp < n)
      minComp++;
   cout << minComp << endl;
   return 0;
}