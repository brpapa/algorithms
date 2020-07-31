/*
   dynamic programming > traveling salesman problem (TSP)
   difficulty: easy
   date: 24/Jan/2020 
   by: @brnpapa
*/
#include <cmath>
#include <cstring>
#include <iostream>
#define INF (int)0x7f7f7f7f
#define MAX_N 11
using namespace std;

int N, dist[MAX_N][MAX_N];

int memo[MAX_N][1 << MAX_N];
int tsp(int i, int bm) {
   // cidade atual i, conjunto de cidades visitadas bm (inclui-se i)

   if ((1 << N) - 1 == bm) // todas cidades foram visitadas
      return dist[i][0];   // volta

   int &ans = memo[i][bm];
   if (ans != -1) return memo[i][bm];

   ans = INF;
   for (int n = 0; n < N; n++)
      if (n != i && !(bm & (1 << n))) // para cada cidade não visitada
         ans = min(ans, dist[i][n] + tsp(n, bm | (1 << n)));
   return ans;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T; cin >> T;
   while (T--) {
      int sizeX, sizeY; cin >> sizeX >> sizeY;
      int x[11], y[11]; cin >> x[0] >> y[0];

      cin >> N; ++N;
      for (int i = 1; i < N; i++)
         cin >> x[i] >> y[i];

      for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
            dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);

      memset(memo, -1, sizeof memo);
      printf("The shortest path has length %d\n", tsp(0, 1));
   }
   return 0;
}
