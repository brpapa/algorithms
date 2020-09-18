/*
   greedy
   difficulty: easy
   date: 23/Apr/2020
   problem: add all
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   int N;
   while (cin >> N && N) {
      priority_queue<int> q;
      while (N--) { int a; cin >> a; q.push(-a); };

      ll cost = 0, sum;
      while (q.size() > 1) {
         sum = -q.top(); q.pop();
         sum += -q.top(); q.pop();
         q.push(-sum);

         cost += sum;
      }
      cout << cost << endl;
   }
   return 0;
}