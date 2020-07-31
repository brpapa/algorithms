/*
   greedy > loading balance
   difficulty: medium
   date: 24/Jan/2020 
   by: @brnpapa
*/
#include <cmath>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      int a[52], N; cin >> N;
      for (int i = 0; i < N; i++) cin >> a[i];
      sort(a, a+N);

      deque<int> A(a, a+N);

      int prevFront = A.front(); A.pop_front();
      int prevBack = A.back();   A.pop_back();
      int ans = abs(prevBack-prevFront);

      while (!A.empty()) {
         int dif[4] = {
            abs(prevBack -  A.front()),
            abs(prevBack -  A.back()),
            abs(prevFront - A.back()),
            abs(prevFront - A.front())
         };

         if (max(dif[0], dif[1]) > max(dif[2], dif[3])) {
            if (dif[0] > dif[1]) {
               ans += abs(prevBack - A.front());
               prevBack = A.front();
               A.pop_front();
            }
            else {
               ans += abs(prevBack - A.back());
               prevBack = A.back();
               A.pop_back();
            }
         }
         else {
            if (dif[2] > dif[3]) {
               ans += abs(prevFront - A.back());
               prevFront = A.back();
               A.pop_back();
            }
            else {
               ans += abs(prevFront - A.front());
               prevFront = A.front();
               A.pop_front();
            }
         }
      }
      printf("Case %d: %d\n", t, ans);
   }
   return 0;
}