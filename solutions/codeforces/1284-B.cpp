/*
   miscellaneous > binary search
   difficulty: medium
   date: 05/Jan/2020 
   by: @brpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1000010
#define MIN -1
#define ll long long
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> mn(N), mx(N); // mn[i] e mx[i] = valores min e max da seq i

   for (int i = 0; i < N; i++) {
      mn[i] = MAX;
      mx[i] = MIN;

      int li; cin >> li;
      while (li--) {
         int s; cin >> s;

         if (s > mn[i]) { // já tem pelo menos 1 ascent
            mn[i] = MIN;
            mx[i] = MAX;
         }
         mn[i] = min(mn[i], s);
         mx[i] = max(mx[i], s);
      }
   }
   sort(mx.begin(), mx.end());

   ll ans = (ll) N * N;
   for (int i = 0; i < N; i++) {
      // decrementa qte de casos onde mn[i] >= mx[j], para 0 <= j <= N (ou seja, quando {mn[i], mn[j]} não forma ascent)
      ans -= upper_bound(mx.begin(), mx.end(), mn[i]) - mx.begin(); 
   }
   cout << ans << endl;
   return 0;
}