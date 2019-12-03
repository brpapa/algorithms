/*
   ad-hoc
   difficulty: easy
   problem: soft drinking
   date: 03/Dec/2019
   author: @brnpapa
*/
#include <algorithm>
#include <iostream>
#define min3(a, b, c) ((a) < (b) ? min(a, c) : min(b, c))
using namespace std;

int main() {
   int N;      // amigos
   int k, l;   // garrafas, cada uma tem l mls de drink
   int c, d;   // limões, cada um cortado em d fatias
   int p;      // gramas de sal
   int nl, np; // mls de drink, gramas de sal (para fazer 1 brinde)

   cin >> N >> k >> l >> c >> d >> p >> nl >> np;
   cout << min3(k * l / nl, c * d, p / np) / N << endl;
   return 0;
}