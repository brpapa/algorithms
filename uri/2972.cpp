/*
   math > combinatorics > binomial coefficient
   difficulty: hard
   problem: less coin tosses
   date: 02/Jan/2020
   solution: calculate how many odd combinations of k heads between N coins are there, that is, the sum of C(N, k)%2 for k in [0 .. N]
   author: @brnpapa
*/
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

int main() {
   ll N;
   cin >> N;
   cout << (ll)pow(2, __builtin_popcountll(N)) << endl;
   return 0;
}