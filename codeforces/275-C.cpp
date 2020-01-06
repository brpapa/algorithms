/*
   ad-hoc > greedy
   difficulty: medium
   problem: k-multiple free set
   date: 05/Jan/2020
   author: @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> ss; // subset

int main() {
   int N, k;
   cin >> N >> k;

   vector<int> s(N);
   for (int &i : s)
      cin >> i;

   sort(s.begin(), s.end());
   for (int i = 0; i < N; i++) {
      if (!(s[i] % k) && ss.count(s[i] / k))
         continue;
      ss.insert(s[i]);
   }
   cout << ss.size() << endl;
   return 0;
}