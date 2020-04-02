/*
   ad-hoc > implementation
   difficulty: medium
   date: 02/Mar/2020 
   solution: maps each position of the robot with the string index, and check if a new position has already been mapped before
   by @brnpapa
*/
#include <iostream>
#include <map>
using namespace std;
#define INF (1 << 30)

map<pair<int, int>, int> grid;
int N; string str;
int l, r; // resposta

void walk(int i, int x, int y) {
   // robô está na posição (x, y) e recebeu instrução p/ str[i]

   if (grid.count(make_pair(x, y))) {
      int nl = grid[make_pair(x, y)];
      int nr = i-1;

      if (nr-nl < r-l) {
         r = nr; 
         l = nl;
      }
   }
   grid[make_pair(x, y)] = i;

   if (i == N) return;
   else if (str[i] == 'L') walk(i+1, x-1, y);
   else if (str[i] == 'R') walk(i+1, x+1, y);
   else if (str[i] == 'U') walk(i+1, x, y+1);
   else if (str[i] == 'D') walk(i+1, x, y-1);
}

int main() {
   int T; cin >> T;
   while (T--) {
      grid.clear(); cin >> N >> str;

      l = 0; r = INF;
      walk(0, 0, 0);

      if (r == INF) cout << -1 << endl;
      else cout << l+1  << " " << r+1 << endl;
   }
   return 0;
}