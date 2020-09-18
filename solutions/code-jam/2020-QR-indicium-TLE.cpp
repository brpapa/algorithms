/*
   brute force > recursive backtracking
   difficulty: easy
   date: 04/Apr/2020
   problem: generate M, where M[i][j] is any value in [1 .. N] (2 <= N <= 5), but without repeting a value in same line or column, and with the sum of the main diagonal equal to K
   by: @brpapa
*/
#include <iostream>
#define ll long long
#define MAX_N 55
#define bitIsOn(S, i) (S & (1 << i))
#define setBit(S, i) (S |= (1 << i))
#define clearBit(S, i) (S &= ~(1 << i))
using namespace std;

int M[MAX_N][MAX_N]; 
int N, K;

ll usedOnRow[MAX_N]; // usedOnRow[r]: bitmask indicando se num já foi usado na linha r
ll usedOnCol[MAX_N]; // usedOnRow[r]: bitmask indicando se num já foi usado na coluna c
int sumDiagonal;

bool hasSolution;

void bt(int i) {
   int r = i/N, c = i%N;
   // define M[r][c] com algum num possivel

   if (hasSolution) return;

   if (i == N*N) {
      hasSolution = true;

      cout << "POSSIBLE" << endl;
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++)
            cout << M[i][j] << " ";
         cout << endl;
      }
      return;
   }
   else {
      for (int num = 1; num <= N; num++) {
         // se num é válido em M[r][c]
         if (!bitIsOn(usedOnRow[r], num) 
          && !bitIsOn(usedOnCol[c], num) 
          && (r != c || sumDiagonal+num <= K)
          && (i != N*N-1 || sumDiagonal+num == K)) {

            M[r][c] = num;

            if (r == c) sumDiagonal += num;
            setBit(usedOnRow[r], num), setBit(usedOnCol[c], num);

            bt(i+1);

            if (r == c) sumDiagonal -= num;
            clearBit(usedOnRow[r], num), clearBit(usedOnCol[c], num);
         }
      }
   }
}

int main() {
   int t = 1, T; cin >> T;
   while (T--) {
      cin >> N >> K;

      hasSolution = false;
      sumDiagonal = 0;
      for (int i = 0; i < N; i++) usedOnRow[i] = 0, usedOnCol[i] = 0;

      printf("Case #%d: ", t++);
      bt(0);
      if (!hasSolution) cout << "IMPOSSIBLE" << endl;
   }
   return 0;
}