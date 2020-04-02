/*
   math > ad-hoc > sequences
   difficulty: medium
   date: 18/Feb/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
   vector<int> humble(6000);
   humble[0] = 1;
   int h2 = 0, h3 = 0, h5 = 0, h7 = 0; // humble[h2] é o próximo a ser multiplicado por 2, etc

   for (int h = 1; h < 6000; h++) {
      humble[h] = min(min(humble[h2]*2, humble[h3]*3), min(humble[h5]*5, humble[h7]*7));
      if (humble[h] == humble[h2]*2) h2++;
      if (humble[h] == humble[h3]*3) h3++;
      if (humble[h] == humble[h5]*5) h5++;
      if (humble[h] == humble[h7]*7) h7++;
   }
   int n;
   while (cin >> n && n) {
      string suff = "th";
      if ((n/10)%10 != 1) { // 2o digito menos significante != 1
         if (n%10 == 1) suff = "st";
         if (n%10 == 2) suff = "nd";
         if (n%10 == 3) suff = "rd";
      }
      printf("The %d%s humble number is %d.\n", n, suff.c_str(), humble[n-1]);
   }
   
   return 0;
}
