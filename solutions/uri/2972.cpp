/*
   math > combinatorics > combinations > binomial coefficient
   difficulty: hard
   date: 02/Jan/2020
   problem: calculate the sum of C(N, k)%2 for all k in [0 .. n], i.e., how many odd combinations of k heads between n coins there are
   hint: just compute 2^qtyBitsOn(n)
   by: @brnpapa
*/
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

int main() {
   ll n; cin >> n;
   cout << (ll)pow(2, __builtin_popcountll(n)) << endl;
   return 0;
}