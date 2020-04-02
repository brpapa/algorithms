/*
   searching > binary search > on answer
   difficulty: medium
   date: 03/Jan/2020 
   by @brnpapa
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, C, T;
vector<int> qtyPopcorns; // qtyPopcorns[i]: qte de pipocas do saco i

// não mais que C competidores conseguem comer tudo em x segundos?
bool can(int x) {
   int qtyCanEat = x * T; // máximo de pipocas que o competidor atual pode comer
   int c = 0;             // competidor atual

   for (int qty : qtyPopcorns) {
      if (qtyCanEat >= qty) {
         qtyCanEat -= qty; // c comeu
      } else {
         c++;
         qtyCanEat = x * T - qty; // próximo c comeu

         if (qtyCanEat < 0 || c == C)
            return false;
      }
   }
   return true;
}

int main() {
   cin >> N >> C >> T;

   int low = 0, high = 0;

   qtyPopcorns.assign(N, 0);
   int timeNeeded;
   for (int &qty : qtyPopcorns) {
      cin >> qty;

      timeNeeded = ceil((double)qty / T);
      low = max(low, timeNeeded);
      high += timeNeeded;
   }

   int ans;
   while (low <= high) {
      int mid = (low + high) / 2;

      if (can(mid)) {
         ans = mid;
         high = mid - 1;
      } else {
         low = mid + 1;
      }
   }
   cout << ans << endl;
   return 0;
}