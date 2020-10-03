/*
   data structures > binary search > on answer
   difficulty: medium
   date: 29/Dec/2019 
   by: @brpapa
*/
#include <cmath>
#include <iostream>
#include <vector>
#define EPS 1e-5
using namespace std;

vector<double> piesVol;

// 1 barriga só pode comer 1 pedaço de 1 torta
bool can(double v, int B) {
   // v: volume do pedaço
   // B: qte de barrigas famintas

   int b = 0;
   for (double pieVol : piesVol) {
      double leftPieVol = pieVol;

      while (leftPieVol - v >= 0) {
         leftPieVol -= v;
         b++;
      }

      if (b >= B)
         return true;
   }
   return false;
}

int main() {
   int T;
   cin >> T;

   while (T--) {
      int N, B;
      cin >> N >> B;
      B++;

      piesVol.assign(N, 0);
      int radii;
      double sumPiesVol = 0;
      for (double &pieVol : piesVol) {
         cin >> radii;
         pieVol = M_PI * radii * radii;
         sumPiesVol += pieVol;
      }

      double low = 0, high = sumPiesVol / B;
      double ans = 0; // volume do pedaço

      while (high - low > EPS) {
         double mid = (low + high) / 2;

         if (can(mid, B)) {
            ans = mid;
            low = mid;
         } else {
            high = mid;
         }
      }
      printf("%.4lf\n", ans);
   }
   return 0;
}