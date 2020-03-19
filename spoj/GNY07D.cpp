/*
   ad-hoc > implementation
   difficulty: easy
   date: 21/Feb/2020
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;
#define VISITED -1

int grid[22][22];
int R, C;

vector<int> binDecoded;
int d;
int dr[4] = {0, 1, 0,-1};
int dc[4] = {1, 0,-1, 0};

void walk(int r, int c) {
   binDecoded.push_back(grid[r][c]);
   grid[r][c] = VISITED;

   bool has = false;
   for (int i = 0; !has && i < 4; i++) {
      int nr = r+dr[d], nc = c+dc[d];
      if (nr < 0 || nr == R || nc < 0 || nc == C || grid[nr][nc] == VISITED)
         d = (d+1)%4;
      else has = true;
   }

   if (has) walk(r+dr[d], c+dc[d]);
}

int main() {
   int T; cin >> T;
   for (int t = 1; t <= T; t++) {
      cin >> R >> C;
      string bin; cin >> bin;
      for (int b = 0; b < R*C; b++)
         grid[b/C][b%C] = bin[b] == '1'? 1:0;

      d = 0;
      binDecoded.clear();
      walk(0, 0);

      vector<char> ans;
      for (int i = 0; i < R*C - (R*C)%5; i += 5) {
         int dec = 0;
         for (int j = 4; j >= 0; j--)
            if (binDecoded[i+4-j])
               dec |= (1 << j);
         ans.push_back(dec == 0? ' ' : 'A'+dec-1);
      }
      
      cout << t << " ";
      for (char c : ans) cout << c;
      cout << endl;
   }
   return 0;
}