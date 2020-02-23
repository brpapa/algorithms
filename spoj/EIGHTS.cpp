/*
   math > ad-hoc > finding pattern
   difficulty: easy
   problem: triple fat ladies
   date: 21/Feb/2020
   author: @brnpapa
*/
#include <iostream>
#define ll long long
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      ll k; cin >> k; k--;
      ll ans = (192+250*(k%4)) + (k/4)*1000;
      cout << ans << endl;
   }
}