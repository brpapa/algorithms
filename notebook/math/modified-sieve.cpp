/*
   Motivation: get the number of different prime factors of the numbers in a range [l..r]
*/
#include <bits/stdc++.h>
using namespace std;

const int UB = 1e6;
vector<int> num_diff_pfs; // num_diff_pfs[i] = qte de fatores primos dos números no intervalo [0..i]

/* O(UB*log(log(UB))) */
void build_sieve() {
   num_diff_pfs.assign(UB, 0);

   for (int i = 2; i < UB; i++)
      if (num_diff_pfs[i] == 0) {
         // cada múltiplo de i (j) tem i como um de seus fatores primos
         for (int j = i; j < UB; j += i)
            num_diff_pfs[j]++;
      }
   
   for (int i = 1; i < UB; i++)
      num_diff_pfs[i] += num_diff_pfs[i-1];
}

int main() {
   build_sieve();
   int l = 2, r = 10;
   int ans = num_diff_pfs[r] - num_diff_pfs[l-1];
   cout << ans << endl;
}
