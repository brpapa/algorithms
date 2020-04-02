/*
   ad-hoc > implementation
   difficulty: easy
   date: 04/Jan/2020 
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, M;
   cin >> N >> M;

   vector<string> s(N), t(M);

   for (string &str : s)
      cin >> str;
   for (string &str : t)
      cin >> str;

   int Q;
   cin >> Q;
   while (Q--) {
      int q;
      cin >> q;
      cout << s[(q - 1) % N] << t[(q - 1) % M] << endl;
   }
   return 0;
}