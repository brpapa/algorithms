/*
   searching > binary search > on answer
   difficulty: hard
   date: 06/Jan/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M, W;
vector<int> hgt;

bool can(int ans) {
   int m = 0;

   vector<int> wt(N, 0); // wt[i]: qte de regadas que inicia na i-ésima flor
   int curr = 0;         // incremento à hgt[i], considerando as regadas anteriores que ainda atinge a flor i

   for (int i = 0; i < N; i++) {
      if (i - W >= 0) 
         curr -= wt[i - W]; // decrementa regadas anteriores que não alcança a flor i

      if (hgt[i] + curr < ans) {
         wt[i] = ans - (hgt[i] + curr);

         curr += wt[i];
         m += wt[i];
         if (m > M)
            return false;
      }
   }
   return true;
}

int main() {
   cin >> N >> M >> W;

   int ans, low = 1e9, high = 1;

   hgt.resize(N);
   for (int &h : hgt) {
      cin >> h;
      low = min(low, h);
      high = max(high, h + M);
   }

   while (low <= high) {
      int mid = (low + high) >> 1;

      if (can(mid)) {
         ans = mid;
         low = mid + 1;
      } else {
         high = mid - 1;
      }
   }
   cout << ans << endl;
   return 0;
}