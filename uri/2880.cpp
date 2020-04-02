/*
   ad-hoc
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <string>
using namespace std;

int contaPosPossiveis(string msg, string crib) {
   int soma = 0;
   //para cada possibilidade i, começando em msg[i]
   for (int i = 0; i <= (msg.size() - crib.size()); i++) {
      bool ok = true;
      //para cada letra de crib
      for (int j = 0; j < crib.size() && ok; j++)
         if (crib.at(j) == msg.at(j + i))
            ok = false;
      if (ok)
         soma++;
   }
   return soma;
}

int main() {
   string msg, crib;
   cin >> msg >> crib;
   cout << contaPosPossiveis(msg, crib) << endl;
   return 0;
}