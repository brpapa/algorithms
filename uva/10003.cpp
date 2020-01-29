/*
   dynamic programming > non-classicals
   difficulty: easy
   problem: cutting sticks
   date: 25/Jan/2020
   author: @brnpapa
*/
//! essa solução está horrível (mas passou), seria melhor considerar como estado os indices (0 à N-1) dos gravetos atuais. Ao considerar o segmento como estado a matriz memo não é completamente usada e há um scan O(N) desnecessário em cada estado
#include <cstring>
#include <iostream>
#include <vector>
#define ll long long
#define INF (ll)0x7f7f7f7f7f7f7f7f
using namespace std;

vector<int> cuts;

ll memo[1010][1010];
ll dp(int l, int r) {
   ll &ans = memo[l][r];
   if (ans != -1) return ans;

   ans = INF;
   for (int cut : cuts)
      if (cut > l && cut < r)
         ans = min(ans, (ll) r-l + dp(cut, r) + dp(l, cut));

   if (ans == INF)  // nao tem corte no intervalo [l .. r]
      ans = 0ll;    // caso base
      
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   while (true) {
      int len; cin >> len;
      if (len == 0) return 0;
   
      int N; cin >> N;
      cuts.resize(N);
      for (int &cut : cuts) cin >> cut;

      memset(memo, -1ll, sizeof memo);
      printf("The minimum cutting is %ld.\n", dp(0, len));
   }
}
