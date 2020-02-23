/*
   searching > two pointers
   difficulty: hard
   problem: glinder
   date: 09/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   ll N, H; cin >> N >> H;

   vector<ll> sl(N), sr(N); // segmentos de sl[i] à sr[i]
   for (int i = 0; i < N; i++)
      cin >> sl[i] >> sr[i];

   vector<ll> sumLen(N + 1); // onde H não decrementa
   sumLen[0] = 0;
   for (int i = 1; i < N + 1; i++)
      sumLen[i] = (sr[i - 1] - sl[i - 1]) + sumLen[i - 1];

   vector<ll> sumDif(N + 1); // onde H decrementa
   sumDif[0] = 0;
   for (int i = 1; i < N; i++)
      sumDif[i] = (sl[i] - sr[i - 1]) + sumDif[i - 1];
   sumDif[N] = INF;

   int l, r = 0; // pointers
   ll maxLen = 0;
   for (l = 0; l < N + 1; l++) {
      // sumDif em [l .. r]: sumDif[r] - sumDif[l]
      while (sumDif[r] - sumDif[l] < H && r + 1 < N + 1)
         r++;

      // sumLen em [l .. r): sumLen[r] - sumLen[l]
      maxLen = max(maxLen, H + sumLen[r] - sumLen[l]);
   }
   cout << maxLen << endl;
   return 0;
}