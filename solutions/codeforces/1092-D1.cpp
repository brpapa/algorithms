/*
   math > ad-hoc > finding pattern
   difficulty: medium
   date: 09/Mar/2020 
   hint: remove adjacent ones whose absolute difference is even (using a stack)
   by: @brpapa
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
   int N; cin >> N;
   stack<int> s;

   for (int n = 0; n < N; n++) {
      int a; cin >> a;
      if (!s.empty() && abs(a-s.top())%2 == 0) s.pop();
      else s.push(a);
   }

   if (s.size() <= 1) cout << "YES" << endl;
   else cout << "NO" << endl;
   
   return 0;
}