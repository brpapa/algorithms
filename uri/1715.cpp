/*
   ad-hoc | basic
   problem: handball
*/
#include <iostream>
using namespace std;

int main() {
   int qteJogadores, qtePartidas, qteGols, ans = 0;
   bool jogouTodas;

   scanf("%d %d", &qteJogadores, &qtePartidas);
   while (qteJogadores--) {
      jogouTodas = true;
      for (int i = 0; i < qtePartidas; i++) {
         scanf("%d", &qteGols);
         if (qteGols == 0)
            jogouTodas = false;
      }
      if (jogouTodas)
         ans++;
   }
   printf("%d\n", ans);
   return 0;
}