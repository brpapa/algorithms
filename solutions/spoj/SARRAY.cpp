/*
   strings > suffix array
   difficulty: medium
   date: 26/Aug/2020
   problem: just build a suffix array in O(N * log N)
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

#define MAX_N 100010
char T[MAX_N];
int N;
int ra[MAX_N], temp_ra[MAX_N];
int sa[MAX_N], temp_sa[MAX_N];
int c[MAX_N];

/* O(N) */
void counting_sort(int k) {
   int i, sum, maxi = max(300, N);
   memset(c, 0, sizeof c);
   for (i = 0; i < N; i++)
      c[i + k < N ? ra[i + k] : 0]++;
   for (i = sum = 0; i < maxi; i++) {
      int t = c[i];
      c[i] = sum;
      sum += t;
   }
   for (i = 0; i < N; i++)
      temp_sa[c[sa[i] + k < N ? ra[sa[i] + k] : 0]++] = sa[i];
   for (i = 0; i < N; i++)
      sa[i] = temp_sa[i];
}

/* O(N * log N) */
void build_sa() {
   int i, k, r;
   for (i = 0; i < N; i++)
      ra[i] = T[i];
   for (i = 0; i < N; i++)
      sa[i] = i;
   for (k = 1; k < N; k <<= 1) {
      counting_sort(k);
      counting_sort(0);
      temp_ra[sa[0]] = r = 0;
      for (i = 1; i < N; i++)
         temp_ra[sa[i]] =
             (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k]) ? r : ++r;
      for (i = 0; i < N; i++)
         ra[i] = temp_ra[i];
      if (ra[sa[N - 1]] == N - 1)
         break;
   }
}

int main() {
   scanf("%100000s", T);
   N = (int)strlen(T);
   T[N++] = '$';

   build_sa();
   for (int i = 1; i < N; i++)
      printf("%d\n", sa[i]);
   return 0;
}
