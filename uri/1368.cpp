/*
   ad-hoc
   difficulty: hard
   problem: colorful cubes
   date: 22/Jun/2019
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

struct Tcubo {
   int cor[6]; //cor da face i

   bool operator==(Tcubo &c) {
      for (int i = 0; i < 6; i++)
         if (this->cor[i] != c.cor[i])
            return false;
      return true;
   }

   void rotaciona(int frente, int topo, int dir, int oposto, int esq, int atras) {
      this->cor[0] = frente;
      this->cor[1] = topo;
      this->cor[2] = dir;
      this->cor[3] = oposto;
      this->cor[4] = esq;
      this->cor[5] = atras;
   }
   void giraSentidoHorario() {
      int tmp = this->cor[0];
      this->cor[0] = this->cor[2];
      this->cor[2] = this->cor[5];
      this->cor[5] = this->cor[4];
      this->cor[4] = tmp;
   }
};


bool saoIguais(Tcubo a, Tcubo b) {
   Tcubo r[6]; //cubo A rotacionado com topo i
   r[0].rotaciona(a.cor[3], a.cor[0], a.cor[2], a.cor[5], a.cor[4], a.cor[1]);
   r[1].rotaciona(a.cor[0], a.cor[1], a.cor[2], a.cor[3], a.cor[4], a.cor[5]);
   r[2].rotaciona(a.cor[0], a.cor[2], a.cor[3], a.cor[4], a.cor[1], a.cor[5]);
   r[3].rotaciona(a.cor[5], a.cor[3], a.cor[2], a.cor[1], a.cor[4], a.cor[0]);
   r[4].rotaciona(a.cor[0], a.cor[4], a.cor[1], a.cor[2], a.cor[3], a.cor[5]);
   r[5].rotaciona(a.cor[1], a.cor[5], a.cor[2], a.cor[0], a.cor[4], a.cor[3]);

   for (int i = 0; i < 6; i++)
      for (int j = 0; j < 4; j++) {
         if (r[i] == b)
            return true;
         r[i].giraSentidoHorario(); //4 possibilidades para cada topo i
      }
   return false;
}

int main() {
   int n;
   Tcubo tmp;

   while (true) {
      cin >> n;
      if (n == 0)
         break;

      vector<Tcubo> cubos;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < 6; j++)
            cin >> tmp.cor[j];
         cubos.push_back(tmp);
      }

      for (int i = 0; i < cubos.size(); i++)
         for (int j = i+1; j < cubos.size(); j++)
            if (saoIguais(cubos[i], cubos[j])) {
               cubos.erase(cubos.begin()+j);
               j--;
            }
      cout << cubos.size() << endl;
   }
   return 0;
}