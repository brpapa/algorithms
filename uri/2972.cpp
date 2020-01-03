/*
   mathematics | combinatorics | combinations | binomial coefficient
   difficulty: medium
   problem: less coin tosses
   date: 02/Jan/2020
   author: @brnpapa
*/
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

int main() {
   ll N;
   cin >> N;

   // somatório de C(N, k)%2, para 0 <= k <= N, pois só sobra quando há qte ímpar de combinações de k caras, dentre N moedas
   cout << (ll)pow(2, __builtin_popcountll(N)) << endl;
   return 0;
}