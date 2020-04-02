/*
   dynamic programming > longest common subsequence (LCS)
   difficulty: easy
   date: 26/Mar/2020
   problem: given a string, determine the minimal quantity of characters to be inserted into it in order to obtain a palindrome
   solution: compute length of string minus lcs between string and reversed string
   by @brnpapa
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string A, B;
int N;

int memo[5050][5050];
int lcs(int i, int j) {
   // i-ésimo posição em A, j-ésima posição em B

   if (i == N || j == N) return 0;

   int &ans = memo[i][j];
   if (ans != -1) return ans;

   if (A[i] == B[j])
      return ans = 1+lcs(i+1, j+1);

   return ans = max(lcs(i+1, j), lcs(i, j+1));
}

int main() {
   cin >> N >> A;
   B = A; reverse(B.begin(), B.end());

   memset(memo, -1, sizeof memo);
   cout << N-lcs(0, 0) << endl;
   return 0;
}
