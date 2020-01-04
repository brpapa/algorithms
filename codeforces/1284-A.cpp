/*
   ad-hoc | implementation
   difficulty: easy
   problem: new year and naming
   date: 04/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, M;
   cin >> N >> M;

   vector<string> s(N), t(M);

   for (string &str: s) cin >> str;
   for (string &str: t) cin >> str;

   int Q, q;
   cin >> Q;
   while (Q--) {
      cin >> q;
      cout << s[(q - 1)%s.size()] << t[(q - 1)%t.size()] << endl;
   }
   return 0;
}