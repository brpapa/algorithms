/*
   ad-hoc
   problem: dice
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int qteJogadores, n, tamTrilha, arm[3], d1, d2, ans;
   bool ngmJogou;
   while (true) {
      cin >> qteJogadores >> tamTrilha;
      if (qteJogadores == 0 && tamTrilha == 0)
         return 0;

      vector<int> pts(qteJogadores, 0);
      vector<bool> podeJogar(qteJogadores, true);

      for (int i = 0; i < 3; i++)
         cin >> arm[i];
      cin >> n; //qte de jogadas

      int j = 0; //1o jogador
      for (int i = 0; i < n; i++, ngmJogou = true) {
         cin >> d1 >> d2;

         while (ngmJogou) {
            if (!podeJogar[j])
               podeJogar[j] = true; //joga na proxima
            else {
               pts[j] += d1 + d2;
               if (pts[j] == arm[0] || pts[j] == arm[1] || pts[j] == arm[2])
                  podeJogar[j] = false; //não joga na proxima
               
               if (pts[j] > tamTrilha)
                  ans = j+1; //vencedor
               ngmJogou = false;
            }
            j = (++j)%qteJogadores;
         }
      }
      cout << ans << endl;
   }
   return 0;
}