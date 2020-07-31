/*
   ad-hoc > implementation
   difficulty: easy
   date: 27/Dec/2019 
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int K;
   cin >> K;

   string digits;
   vector<int> qtyPanelsToPressAtTime(10, 0);
   for (int i = 0; i < 4; i++) {
      cin >> digits;
      for (int j = 0; j < 4; j++) {
         // '1' = 49, '9' = 57)
         int dig = (int)digits[j];

         if (dig >= 49 && dig <= 57)
            qtyPanelsToPressAtTime[dig - 48]++;
      }
   }

   for (int qty : qtyPanelsToPressAtTime) {
      if (qty > 2 * K) {
         cout << "NO" << endl;
         return 0;
      }
   }
   cout << "YES" << endl;
   return 0;
}