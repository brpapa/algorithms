/*
   math > combinatorics > combinations > multi-combinations
   difficulty: medium
   date: 19/Jun/2020
   hint: C(n+5-1,5) * C(n+3-1,3)
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   ll n; cin >> n;
   ll bugs = (n+4)*(n+3)*(n+2)*(n+1)*n/120;
   ll features = (n+2)*(n+1)*n/6;
   cout << bugs*features << endl; 
   return 0;
}
