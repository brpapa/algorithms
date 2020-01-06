/*
   ad-hoc
   problem: the dark elf
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

struct Trena {
   string nome;
   int peso, idade;
   double altura;
};

bool comp(const Trena &a, const Trena &b) {
   if (a.peso > b.peso)
      return true;
   if (a.peso < b.peso)
      return false;

   //para pesos iguais
   if (a.idade < b.idade)
      return true;
   if (a.idade > b.idade)
      return false;

   //para pesos e idades iguais
   if (a.altura < b.altura)
      return true;
   if (a.altura > b.altura)
      return false;

   //para pesos, idades e alturas iguais
   if (a.nome < b.nome)
      return true;
   return false;
}

int main() {
   int T, qteRenas, vagasTreno;
   Trena r, aux;
   vector<Trena> v;

   cin >> T;
   for (int t = 1; t <= T; t++) {
      cin >> qteRenas >> vagasTreno;
      v.clear();
      for (int i = 0; i < qteRenas; i++) {
         cin >> r.nome >> r.peso >> r.idade >> r.altura;
         v.push_back(r);
      }
      //compara passando comp como função objeto
      sort(v.begin(), v.end(), comp);

      cout << "CENARIO {" << t << "}\n";
      for (int i = 0; i < vagasTreno; i++)
         cout << i+1 << " - " << v[i].nome << endl;
   }
   return 0;
}