/*
   greedy
   difficulty: medium
   date: 02/Apr/2020
   problem: given the two-sided values of N cards, what is the minimum number of turns in the cards so that at least half of them are the same front?; they are initially facing upwards
   by: @brnpapa
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
   int N; cin >> N;
   multiset<int> front, back;
   set<int> values;
   for (int n = 0; n < N; n++) {
      int f, b; cin >> f >> b; 
      front.insert(f), values.insert(f);
      if (b != f) back.insert(b), values.insert(b);
   }

   int ans = N+1;
   for (int v : values) {
      int a = front.count(v);
      int b = back.count(v);
      int t = (N+1)/2;

      if (a+b >= t) ans = min(ans, max(0, t-a));
   }
   cout << (ans == N+1? -1: ans) << endl;

   return 0;
}