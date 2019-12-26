/*
   ad-hoc
   difficulty: medium
   problem: A and B and team training
   date: 24/Dec/2019
   author: @brnpapa
*/
#include <iostream>
using namespace std;
typedef long long int lld;

int main() {
   int EXP, NB;
   cin >> EXP >> NB; // experts, newbiews

   int ans = 0;
   for (int i = 0; i <= EXP; i++) {
      int qtyTeams = i; // times com 1 exp e 2 nbs cada

      int leftEXP = EXP - i;
      int leftNB = NB - 2 * i;

      if (leftNB >= 0) {
         // += leftNB, se leftEXP >= 2*leftNB
         // += leftEXP/2, se leftEXP <= 2*leftNB
         qtyTeams += min(leftEXP / 2, leftNB); // times com 2 exp e 1 nb cada

         ans = max(ans, qtyTeams);
      }
   }
   cout << ans << endl;
   return 0;
}