/*
   math > ad-hoc > finding pattern
   difficulty: easy
   date: 21/Feb/2020 
   by: @brnpapa
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