/*
   searching > binary search > on answer
   difficulty: medium
   date: 26/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prices;
ll x, a, y, b, K; 

// calcula o maior k possível em [1 .. ans] e testa se ele é suficiente, pois prioriza os tickets mais caros nas posições que terão uma taxa de contribuição maior
bool can(int ans) {
   ll k = 0;  // soma atual
   int p = 0; // preço do ingresso atual

   if (x < y) swap(x, y), swap(a, b);

   for (int i = 1; i <= ans; i++) if (i%a == 0 && i%b == 0) k += prices[p++] * (x+y);
   for (int i = 1; i <= ans; i++) if (i%a == 0 && i%b != 0) k += prices[p++] * x;
   for (int i = 1; i <= ans; i++) if (i%a != 0 && i%b == 0) k += prices[p++] * y;

   return k >= K;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      prices.resize(N); for (int &price : prices) cin >> price, price /= 100;
      cin >> x >> a >> y >> b >> K;

      sort(prices.rbegin(), prices.rend());
      int low = 1, high = N;
      int ans = -1;

      while (low <= high) {
         int mid = (low + high) >> 1;
         if (can(mid)) ans = mid, high = mid-1;
         else          low = mid+1;
      }
      cout << ans << endl;
   }   
   return 0;
}
