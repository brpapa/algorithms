/*
   substring search > knuth-morris-pratt (KMP)
   problem: musical plagiarism
   author: @brnpapa
*/
#include <iostream>
using namespace std;

void str2vet_int(string aux, int &n) {
   if (aux == "A")
      n = 1;
   else if (aux == "A#" || aux == "Bb")
      n = 2;
   else if (aux == "B" || aux == "Cb")
      n = 3;
   else if (aux == "C" || aux == "B#")
      n = 4;
   else if (aux == "C#" || aux == "Db")
      n = 5;
   else if (aux == "D")
      n = 6;
   else if (aux == "D#" || aux == "Eb")
      n = 7;
   else if (aux == "E" || aux == "Fb")
      n = 8;
   else if (aux == "F" || aux == "E#")
      n = 9;
   else if (aux == "F#" || aux == "Gb")
      n = 10;
   else if (aux == "G")
      n = 11;
   else if (aux == "G#" || aux == "Ab")
      n = 12;
}
void distMeioTons(int vet[], int &tam) {
   tam--;
   for (int i = 0; i < tam; i++) {
      vet[i] = vet[i + 1] - vet[i];
      if (vet[i] < 0)
         vet[i] += 12; //pois é ciclico
   }
}
void calculaPrefix(int aux[], int subVet[], int tamSubVet) {
   int i = 0, j = -1;
   aux[0] = -1;
   while (i < tamSubVet) {
      while (j >= 0 && subVet[i] != subVet[j])
         j = aux[j];
      aux[++i] = ++j;
   }
}
//aplica técnica de busca em string KMP para verificar se subVet está contido em vet
bool kmp(int vet[], int tamVet, int subVet[], int tamSubVet) {
   int aux[100000], j = 0;
   calculaPrefix(aux, subVet, tamSubVet);
   for (int i = 0; i < tamVet; i++) {
      while (j >= 0 && vet[i] != subVet[j])
         j = aux[j];
         
      if (++j == tamSubVet)
         return true;
   }
   return false;
}

int main() {
   int notas[100000], m, trechoSuspeito[10000], t;
   string aux;
   while (true) {
      cin >> m >> t;
      if (m == 0 && t == 0)
         return 0;

      for (int i = 0; i < m; i++) {
         cin >> aux;
         str2vet_int(aux, notas[i]);
      }
      for (int i = 0; i < t; i++) {
         cin >> aux;
         str2vet_int(aux, trechoSuspeito[i]);
      }
      distMeioTons(notas, m);
      distMeioTons(trechoSuspeito, t);
      printf("%s\n", kmp(notas, m, trechoSuspeito, t) ? "S" : "N");
   }
   return 0;
}
