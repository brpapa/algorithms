/*
   greedy
   difficulty: easy
   date: 03/Oct/2020
   problem: remove D digits from the given number, in a such way that the remain number is maximum
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N, D;
   while (cin >> N >> D && (N || D)) {
      string s; cin >> s;
      string ans;

      int d = D; // remaining to delete
      int i = 0; // current index
      while (i < N && d > 0) {
         // cout << i << " " << d << endl;
         auto max = max_element(s.begin()+i, s.begin()+i+d+1);
         int i_max = max-s.begin();

         d -= i_max-i;
         ans.push_back(*max);
         if (ans.size() == N-D) break;

         i = i_max+1;
      }

      while (i < N && ans.size() < N-D) ans.push_back(s[i++]);
      cout << ans << endl;
   }
   return 0;
}

/*
   18412923, i = 0, d = 3

   18412923, i = 2, d = 2
    8412923

   18412923, i = 3, d = 2
    84  923
*/