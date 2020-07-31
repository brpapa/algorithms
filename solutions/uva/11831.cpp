/*
   graphs > traversal
   difficulty: easy
   date: 27/Feb/2020 
   hint: consider grid as an implicit graph and walk through it, or just rotate the robot, for each received instruction
   by: @brnpapa
*/
#include <iostream>
using namespace std;

int R, C, I; 
char grid[110][110];
char instructions[5*10010];

char orientations[4] = {'N', 'L', 'S', 'O'}; // -> right
int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0,-1};

int walk(int i, int rr, int rc, int ro) {
   // instructions[i]: received instruction
   // grid[rr][rc]: robot position
   // orientations[ro]: robot orientation

   if (i == I) return 0;

   if (instructions[i] == 'D') return walk(i+1, rr, rc, (ro+1) % 4);
   if (instructions[i] == 'E') return walk(i+1, rr, rc, ro == 0? 3: ro-1);

   // robo se movimenta para onde está orientado
   int nrr = rr+dr[ro], nrc = rc+dc[ro];

   // new robot row or ner robot column is invalid
   if (nrr < 0 || nrr == R || nrc < 0 || nrc == C || grid[nrr][nrc] == '#')
      return walk(i+1, rr, rc, ro);

   if (grid[nrr][nrc] == '*') {
      grid[nrr][nrc] = '.'; // evita nova contagem no futuro
      return 1 + walk(i+1, nrr, nrc, ro);
   }

   return walk(i+1, nrr, nrc, ro);
}

int main() {
   while (cin >> R >> C >> I && (R || C || I)) {
      int rr, rc, ro = -1;

      for (int r = 0; r < R; r++) 
         for (int c = 0; c < C; c++) {
            cin >> grid[r][c];

            for (int o = 0; o < 4 && ro == -1; o++)
               if (grid[r][c] == orientations[o]) {
                  rr = r; rc = c; ro = o;
                  grid[r][c] = '.';
               }
         }

      for (int i = 0; i < I; i++) cin >> instructions[i];

      cout << walk(0, rr, rc, ro) << endl;
   }
   return 0;
}
