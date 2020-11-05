/*
   Motivation: given the dimensions of N matrices, output a complete parenthesized product that minimizes the number of scalar multiplications needed.

   For multiply a PxQ matrix A by a QxR matrix B we need PxQxR scalar multiplications.

   For example: 
      Given D = {10, 100, 5, 50}, which implies that the matrix:
         A1 is 10x100
         A2 is 100x5
         A3 is 5x50 
   
      We can completely parenthesize these 3 matrices in 2 ways:
         (A1x(A2xA3)) = 100x5x50 + 10x100x50 = 75000 scalar multiplications
         ((A1xA2)xA3) = 10x100x5 + 10x5x50   = 7500  scalar multiplications

      We can completely parenthesize 4 matrices in 5 ways:
         (A1x(A2x(A3xA4)))
         (A1x((A2xA3)xA4))
         ((A1xA2)x(A3xA4))
         ((A1x(A2xA3))xA4)
         (((A1xA2)xA3)xA4)
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
vector<int> D = {10, 100, 5, 50};

vector<vector<int>> memo;

/* O(N^3) - returns the needed for A[i] x A[i+1] x ... x A[j] (i >= 1) */
int dp(int i, int j) {
   // sub-interval [i-1..j] of D

   if (i == j) return 0;

   int &ans = memo[i][j];
   if (ans != -1) return ans;

   ans = INF;
   for (int k = i; k <= j-1; k++)
      ans = min(ans, D[i-1]*D[k]*D[j] + dp(i, k) + dp(k+1, j));

   return ans;
}

int main() {
   memo.assign(D.size()+1, vector<int>(D.size()+1, -1));
   cout << dp(1, D.size()-1) << endl;
   return 0;
}