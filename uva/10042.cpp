/*
   math > number theory > prime numbers > prime factorization
   difficulty: easy
   date: 13/Feb/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sumDigits(int n) {
   int sum = 0;
   while (n > 0) {
      sum += n%10;
      n /= 10;
   }
   return sum;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;

      for (int ans = n+1; true; ans++) {
         int tmp = ans; vector<int> ansFactors;

         for (int f = 2; f <= sqrt(tmp) && tmp > 0; f++)
            while (tmp%f == 0) {
               ansFactors.push_back(f);
               tmp /= f;
            }
         if (ansFactors.empty()) continue; // ans é primo, logo não é smith
         if (tmp > 1) ansFactors.push_back(tmp);

         int sumFactorsDigits = 0;
         for (int f: ansFactors) sumFactorsDigits += sumDigits(f);
         if (sumDigits(ans) == sumFactorsDigits) {
            cout << ans << endl; break;
         }
      }
   }
   return 0;
}
