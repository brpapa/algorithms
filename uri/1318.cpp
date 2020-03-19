/*
   ad-hoc
   difficulty: none
   date: none
   problem: none
   by @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int qteBilhetes, qtePessoas, aux;
   while (true) {
      cin >> qteBilhetes >> qtePessoas;
      if (qteBilhetes == 0 && qtePessoas == 0)
         return 0;

      vector<int> bilhetes(qteBilhetes + 1, 0);
      for (int i = 0; i < qtePessoas; i++) {
         cin >> aux;
         bilhetes[aux]++;
      }

      int soma = 0;
      for (int i = 1; i <= qteBilhetes; i++)
         if (bilhetes[i] > 1)
            soma++;

      cout << soma << endl;
   }
   return 0;
}
