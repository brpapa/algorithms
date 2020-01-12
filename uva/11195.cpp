/*
   brute force > backtracking > n-queens
   difficulty: medium
   problem: another n-queen problem
   date: 12/Jan/2020
   author: @brnpapa
   alt: bitmasks
*/
#include <bitset>
#include <iostream>
#define setBit(S, i) (S |= (1 << (i)))
#define clearBit(S, i) (S &= ~(1 << (i)))
#define bitIsOn(S, i) (S & (1 << (i)))
using namespace std;

int r = 0, ld = 0, rd = 0; // bitmasks

char board[15][15];
int ans, N;

void bt(int c) {
   if (c == N) {
      ans++; return;
   }

   for (int r = 0; r < N; r++)
      if (board[r][c] != '*' && !bitIsOn(r, r) && !bitIsOn(ld, r-c+N-1) && !bitIsOn(rd,r+c)) {
         setBit(r, r); setBit(ld, r-c+N-1); setBit(rd, r+c);
         bt(c + 1);
         clearBit(r, r); clearBit(ld, r-c+N-1); clearBit(rd, r+c); // restaura
      }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   int T = 0;
   while (true) {
      cin >> N; if (N == 0) break;
      for (int r = 0; r < N; r++)
         for (int c = 0; c < N; c++)
            cin >> board[r][c];
      
      ans = 0;
      bt(0);
      cout << "Case " << ++T << ": " << ans << endl;
   }
   return 0;
}