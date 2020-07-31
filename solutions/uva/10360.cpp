/*
   brute force > iterative
   difficulty: easy
   date: 13/Jan/2020 
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#define MAX 1025
using namespace std;

int killed[MAX][MAX]; // quantos ratos morreriam se a bomba estive na posicao

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T; cin >> T;
   while (T--) {
      int D, N; cin >> D >> N;
      memset(killed, 0, sizeof(killed));
      for (int n = 0; n < N; n++) {
         int X, Y, P; cin >> X >> Y >> P;

         for (int x = max(X-D, 0); x <= min(X+D, MAX-1); x++)
            for (int y = max(Y-D, 0); y <= min(Y+D, MAX-1); y++)
               killed[x][y] += P;
      }

      int maxKilled = -1, maxX, maxY;
      for (int x = 0; x < MAX; x++)
         for (int y = 0; y < MAX; y++)
            if (killed[x][y] > maxKilled) {
               maxKilled = killed[x][y];
               maxX = x; maxY = y;
            }
      cout << maxX << " " << maxY << " " << maxKilled << endl;
   }  
   return 0;
}