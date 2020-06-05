/*
   brute force > recursive backtracking
   difficulty: easy
   date: 22/May/2020
   problem: chess with a single horse against up to 8 pawns; print the length of the minimum sequence of horse moves if it wins
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
#define REMOVED -1

vector<int> newHorseMoves(int h) {
   int r = (h-1)/8, c = (h-1)%8;

   vector<int> ret;
   int dr[8] = {-2,-2, 2, 2,-1,-1, 1, 1};
   int dc[8] = {-1, 1,-1, 1,-2, 2,-2, 2};
   for (int d = 0; d < 8; d++) {
      int nr = r+dr[d], nc = c+dc[d];
      if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;
      ret.push_back(nr*8 + 1 + nc);
   }
   return ret;
}

bool hasSomePawn(int p[8]) {
   for (int i = 0; i < 8; i++)
      if (p[i] != REMOVED) return true;
   return false;
}

int bt(int h, int p[8]) {
   // cavalo na posição atual h, peoes nas posições p

   if (!hasSomePawn(p)) return 0;

   int ans = INF;
   // para cada nova posição válida do cavalo, sem alterar p (backtracking)
   for (int nh : newHorseMoves(h)) {
      int np[8]; for (int i = 0; i < 8; i++) np[i] = p[i];

      // se o cavalo comeu um peao
      for (int i = 0; i < 8; i++) if (np[i] == nh) np[i] = REMOVED;

      // anda todos os peoes e testa se alguém virou rei ou comeu o cavalo
      for (int i = 0; i < 8; i++) if (np[i] != REMOVED) np[i] += 8;
      bool inv = false;
      for (int i = 0; i < 8; i++) if (np[i] > 64 || np[i] == nh) inv = true;
      if (inv) continue;

      ans = min(ans, 1 + bt(nh, np));
   }
   return ans;
}

int main() {
   int P;
   while (cin >> P && P) {
      int p[8], i = 0;
      while (i < P) cin >> p[i++];
      while (i < 8) p[i++] = REMOVED;
      int h; cin >> h;

      int ans = bt(h, p);
      if (ans == INF) cout << "impossible" << endl;
      else cout << ans << endl;
   }
   return 0;
}
