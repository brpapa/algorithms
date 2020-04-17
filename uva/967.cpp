/*
   techniques > two pointers
   difficulty: medium
   date: 30/Mar/2020
   problem: pope
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int Y, N; 
   while (cin >> Y >> N) {
      vector<int> A(N); for (int &a : A) cin >> a;

      int K = Y;
      int k = 0;

      int l, r = 0;

      int ans = 0, ansLower, ansUpper;
      for (l = 0; l < N; l++) {
         if (l > 0) k--;

         // k: qte de papas em A[l:r-1]
         while (r < N && A[l]+K-1 >= A[r]) k++, r++;

         if (k > ans)
            ans = k, ansLower = A[l], ansUpper = A[r-1];
      }
      cout << ans << " " << ansLower << " " << ansUpper << endl;
   }
   return 0;
}
