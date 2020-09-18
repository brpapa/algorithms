/*
   brute force > recursive backtracking > pruned permutations
   difficulty: easy
   date: 14/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

bitset<10> used; // used[v]: v já foi usado na permutação atual
int p[10];       // permutação atual

int A[10], K;
bool hasSolution;

// p[0:i-1] é válido?
bool check(int i, int v) {
   int sum = 0;
   for (int k = 0; k < i; k++) {
      sum += p[k]*A[k];
      if (sum > K) return false;
   }
   return sum + (v*A[i]) <= K;
}

// constroi p[i]
void bt(int i) {
   if (hasSolution) return;

   if (i == 10) {
      hasSolution = true;
      for (int i = 0; i < 9; i++)
         cout << p[i] << " ";
      cout << p[9] << endl;
      return;
   }

   for (int v = 0; v < 10; v++) {
      if (!used[v] && check(i, v)) {
         p[i] = v;

         used[v] = 1;
         bt(i+1);
         used[v] = 0;
      }
   }
}

int main() {
   int T; cin >> T;
   while (T--) {
      for (int i = 0; i < 10; i++) cin >> A[i];
      cin >> K;

      hasSolution = false;
      used.reset();

      bt(0);
      if (!hasSolution) cout << -1 << endl;
   }
   return 0;
}
