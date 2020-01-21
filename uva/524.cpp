/*
   brute force > recursive backtracking > pruned permutations
   difficulty: medium
   problem: prime ring problem
   date: 13/Jan/2020
   author: @brnpapa
*/
#include <bitset>
#include <iostream>
using namespace std;

bool isPrime[32] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};

int N, p[16];
bitset<16+1> used; // used[v] é true, se p[i] == v, para algum 0 <= i < N

// p[i] pode ter valor v?
bool ok(int i, int v) {
   return isPrime[p[i-1]+v];
}

void bt(int i) {
   // gera p[i]

   if (i == N && isPrime[p[N-1]+p[0]]) {
      for (int i = 0; i < N-1; i++) cout << p[i] << " "; cout << p[N-1] << "\n";
      return;
   }
   for (int v = 2; v <= N; v++)
      if (!used[v] && ok(i, v)) {
         p[i] = v;
         used[v] = true;
         bt(i+1);
         used[v] = false;
      }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T = 0;
   while (cin >> N) {
      cout << (T > 0? "\n":"") << "Case " << ++T << ":\n";
      for (int i = 0; i < N; i++) p[i] = i+1;
      used.reset();
      used[1] = true; // p[0] é 1
      bt(1);
   }
   return 0;
}