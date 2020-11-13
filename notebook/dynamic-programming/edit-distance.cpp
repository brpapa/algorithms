/*
   Edit distance (string alignment)
   
   Motivation: given two strings A and B, find the minimum number of A operations required to convert A to B, where inserting, deleting or replacing a character from A is counted as 1 operation.

   Example:
      A: "ACAATCC" -> "A_CAATCC"
      B: "AGCATGC" -> "AGC_ATGC"
                      "AGC ATGC" 
                        I D  R  -> 3 operations in A
*/
#include <bits/stdc++.h>
#define min3(a, b, c) ((a) < (b)? min(a, c) : min(b, c))
using namespace std;

/* input */
string A = "ACAATCC"; int N = A.size();
string B = "AGCATGC"; int M = B.size();

vector<vector<int>> memo;

int dp(int i, int j) {
   // current substrings A[0..i-1] and B[0..j-1]

   if (i == 0 && j == 0) return 0;
   if (j == 0) return i; // delete all A[0..i-1]
   if (i == 0) return j; // insert all B[0..j-1] in A

   int &ans = memo[i][j];
   if (ans != -1) return ans;

   if (A[i-1] == B[j-1]) return ans = dp(i-1, j-1);
   return ans = min3(
      1 + dp(i-1, j-1), // replace A[i] with B[j]
      1 + dp(i-1, j),   // delete A[i]
      1 + dp(i, j-1)    // insert B[j] in A[i]
   );
}

int main() {
   memo.assign(N+1, vector<int>(M+1, -1));
   cout << dp(N, M) << endl;
}