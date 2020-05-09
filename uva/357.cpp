/*
   dynamic programming > 0-1 knapsack > subset sum > with repetition
   difficulty: easy
   date: 19/Mar/2020
   by: @brnpapa
*/
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;

const int N = 5;
int A[N] = {1, 5, 10, 25, 50};

ll memo[5][30030];
ll dp(int n, int s) {
   // n-ésima moeda, soma S-s do subconjunto atual

   if (s == 0)          return 1ll;
   if (n == N || s < 0) return 0ll;

   ll &ans = memo[n][s];
   if (ans != -1) return ans;

   return ans = dp(n+1, s) + dp(n, s-A[n]);
}

int main() {
   memset(memo, -1, sizeof memo);

   int S;
   while (cin >> S) {
      ll ways = dp(0, S);
      printf("There %s %lld %s to produce %d cents change.\n", 
      ways == 1? "is only":"are", ways, ways == 1? "way":"ways", S);
   }
   return 0;
}
