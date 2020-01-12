/*
   brute force > iterative > all subsets
   difficulty: easy
   problem: bars
   date: 11/Jan/2020
   author: @brnpapa
   alt: bitmasks
*/
#include <iostream>
#include <vector>
#define bitIsOn(S, i) (S & (1 << i))
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T; cin >> T;
   while (T--) {
      int K; cin >> K;
      int N; cin >> N;
      vector<int> lenBars(N); for (int &l : lenBars) cin >> l;

      bool ok = false;
      for (int bm = 0; bm < (1 << N) && !ok; bm++) {
         int k = 0;
         for (int j = 0; j < N; j++)
            if (bitIsOn(bm, j))
               k += lenBars[j];
         
         if (k == K) ok = true;
      }
      cout << (ok? "YES":"NO") << endl;
   }
	return 0;
}
