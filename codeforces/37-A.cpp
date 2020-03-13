/*
   ad-hoc
   difficulty: easy
   problem: towers
   date: 02/Mar/2020
   author: @brnpapa
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> count(1010, 0);
   set<int> s;
   for (int n = 0; n < N; n++) {
      int a; cin >> a;
      count[a]++;
      s.insert(a);
   }
   sort(count.rbegin(), count.rend());

   cout << count[0] << " " << s.size() << endl;
   return 0;
}