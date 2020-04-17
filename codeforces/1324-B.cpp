/*
   greedy
   difficulty: easy
   date: 14/Mar/2020
   problem: given a sequence of integers, is there a subsequence palindrome of size 3?
   solution: check if there are two equal non-adjacent numbers using brute force
   by: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N); for (int &a : A) cin >> a;

      bool has = false;
      for (int i = 0; i < N && !has; i++)
         for (int j = i+2; j < N; j++)
            if (A[i] == A[j]) has = true;

      cout << (has? "YES":"NO") << endl;
   }
   return 0;
}
