/*
   ad-hoc > implementation
   difficulty: easy
   date: 29/Dec/2019
   problem: none
   by @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N, L;
   cin >> N >> L; // N lanterns, street bounds: [0 .. L]

   vector<int> lanterns(N);
   for (int &l : lanterns)
      cin >> l;

   sort(lanterns.begin(), lanterns.end());

   int maxDistBetween = 0;
   for (int i = 1; i < lanterns.size(); i++)
      maxDistBetween = max(maxDistBetween, lanterns[i] - lanterns[i - 1]);

   int maxDistBorders = max(lanterns.front(), L - lanterns.back());

   printf("%.10f\n", max((double)maxDistBetween / 2, (double)maxDistBorders));
   return 0;
}