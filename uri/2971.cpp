/*
   ad-hoc > simulation
   difficulty: medium
   date: 19/Sep/2019 
   by @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define next(p) ((p%n)+1)
using namespace std;
   
map<char, int> cardId;
int n, k; // k = quem começa

vector<int> cardsFromPlayer[15]; // cartas atuais do jogador i
bool canPassWildcard[15];
int winningPlayer;

struct Tcard {
   int id, pos, rep;
   
   Tcard(int v, int p, int r) {
      this->id = v;
      this->pos = p; // posicao no vector original
      this->rep = r; // qte de ocorrências
   }
   // carta mais propensa a sair
   bool operator<(const Tcard &p) const {
      if (this->rep == p.rep)
         return this->id < p.id;

      return this->rep < p.rep;
   }
};


// retorna a posição em v da carta escolhida do jogador p
int choiceCard(int p, vector<int> v) {
   vector<Tcard> tmp;
   for (int i = 0; i < v.size(); i++) {
      // coringa
      if (v[i] == 0) {
         if (!canPassWildcard[p]) {
            canPassWildcard[p] = true; // na próxima pode
            continue;
         }
         else {
            canPassWildcard[p] = false;
            return i; // pos do coringa em v
         }
      }

      Tcard c(v[i], i, 1); // id, pos, rep
      for (int j = 0; j < v.size(); j++)
         if (j != i && v[j] == v[i])
            c.rep++;

      tmp.push_back(c);
   }
   sort(tmp.begin(), tmp.end());

   return tmp[0].pos;
}

bool isWinningCards(vector<int> v) {
   for (int i = 1; i < v.size(); i++)
      if (v[0] != v[i])
         return false;
   return true;
}

void init() {
   cardId['*'] = 0;
   cardId['A'] = 1;
   cardId['2'] = 2;
   cardId['3'] = 3;
   cardId['4'] = 4;
   cardId['5'] = 5;
   cardId['6'] = 6;
   cardId['7'] = 7;
   cardId['8'] = 8;
   cardId['9'] = 9;
   cardId['D'] = 10;
   cardId['Q'] = 11;
   cardId['J'] = 12;
   cardId['K'] = 13;

   memset(canPassWildcard, false, sizeof(canPassWildcard));
   cardsFromPlayer[k].push_back(cardId['*']);
   winningPlayer = -1; // ninguém ganhou
}

int main() {
   cin >> n >> k;
   init();

   char cc;
   for (int p = 1; p <= n; p++) {
      for (int c = 0; c < 4; c++) {
         cin >> cc;
         cardsFromPlayer[p].push_back(cardId[cc]);
      }
      
      // já existe alguém que não seja o primeiro a jogar com mão vencedora
      if (isWinningCards(cardsFromPlayer[p]) && winningPlayer == -1 && p != k)
         winningPlayer = p;
   }

   int posCardChoiced, cardChoiced;
   vector<int>::iterator itCardChoiced;

   // para cada jogador p, enquanto ninguém ganhou
   for (int p = k; winningPlayer == -1; p = next(p)) {
      posCardChoiced = choiceCard(p, cardsFromPlayer[p]);

      cardChoiced = cardsFromPlayer[p][posCardChoiced];
      itCardChoiced = cardsFromPlayer[p].begin() + posCardChoiced;

      // passa carta
      cardsFromPlayer[p].erase(itCardChoiced);
      cardsFromPlayer[next(p)].push_back(cardChoiced);

      if (isWinningCards(cardsFromPlayer[p]))
         winningPlayer = p;
   }
   cout << winningPlayer << endl;
   return 0;
}