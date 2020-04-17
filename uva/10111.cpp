/*
   math > game theory > minimax
   difficulty: medium
   date: 12/Apr/2020
   problem: given a state of a tic tac toe board, check if X will win independent of the O movement
   solution: minimax + memo + backtracking
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef array<array<char,4>,4> Tboard;

const int INF = 1 << 30;
const int pX = -1, pY = 1;

/*
   -1,  se pX vence
   1,   se pY vence
   0,   se empata
   INF, se ainda tem jogo
*/
int checkWinner(Tboard board) {
   vector<array<pii,4>> possibilities = {
      { pii(0, 0), pii(0, 1), pii(0, 2), pii(0, 3) },
      { pii(1, 0), pii(1, 1), pii(1, 2), pii(1, 3) },
      { pii(2, 0), pii(2, 1), pii(2, 2), pii(2, 3) },
      { pii(3, 0), pii(3, 1), pii(3, 2), pii(3, 3) },
      { pii(0, 0), pii(1, 0), pii(2, 0), pii(3, 0) },
      { pii(0, 1), pii(1, 1), pii(2, 1), pii(3, 1) },
      { pii(0, 2), pii(1, 2), pii(2, 2), pii(3, 2) },
      { pii(0, 3), pii(1, 3), pii(2, 3), pii(3, 3) },
      { pii(0, 0), pii(1, 1), pii(2, 2), pii(3, 3) },
      { pii(0, 3), pii(1, 2), pii(2, 1), pii(3, 0) },
   };

   for (auto pos : possibilities) {
      char p = board[pos[0].first][pos[0].second];

      if (p != '.' 
       && p == board[pos[1].first][pos[1].second]
       && p == board[pos[2].first][pos[2].second]
       && p == board[pos[3].first][pos[3].second])
         return p == 'x'? pX : pY;
   }

   for (int r = 0; r < 4; r++)
      for (int c = 0; c < 4; c++)
         if (board[r][c] == '.') return INF;
   return 0;
}

map<Tboard, int> memo;

// retorna o player vencedor
int minimax(int p, Tboard board) {
   // jogador atual p, estado atual do jogo board

   if (memo.count(board)) return memo[board];
   int &ans = memo[board];

   ans = checkWinner(board);
   if (ans != INF) return ans;

   ans *= p * (-1);

   for (int r = 0; r < 4; r++)
      for (int c = 0; c < 4; c++)
         if (board[r][c] == '.') {

            board[r][c] = (p == pX)? 'x' : 'o';   
            int maybe = minimax(p * (-1), board);
            board[r][c] = '.';

            if (p == pX) ans = min(ans, maybe);
            else         ans = max(ans, maybe);
         }
   return ans;
}

int main() {
   char c;
   while (cin >> c && c != '$') {
      Tboard board;
      for (int r = 0; r < 4; r++)
         for (int c = 0; c < 4; c++)
            cin >> board[r][c]; // 'x', 'o' ou '.'

      pii sol = {-1, -1};

      for (int r = 0; r < 4; r++)
         for (int c = 0; c < 4; c++)
            if (board[r][c] == '.') {
               board[r][c] = 'x';
               if (minimax(pY, board) == pX && sol == pii(-1, -1)) sol = {r, c};
               board[r][c] = '.';
            }

      if (sol == pii(-1, -1)) cout << "#####" << endl;
      else cout << "(" << sol.first << "," << sol.second << ")" << endl;
   } 
   return 0;
}