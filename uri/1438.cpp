/*
   ad-hoc | basic
   problem: unloading boxes
*/
#include <iostream>
#define MAX 1000
using namespace std;

int main() {
   int qteCaixasTotal, qtePilhas, qteCaixas, caixa;
   while (true) {
      cin >> qteCaixasTotal >> qtePilhas;
      if (qteCaixasTotal == 0 && qtePilhas == 0)
         return 0;

      int tam[MAX], inv, ans;
      for (int i = 0; i < qtePilhas; i++) {
         cin >> qteCaixas;
         tam[i] = qteCaixas; //tamanho da pilha i
       
         for (int p = 0; p < qteCaixas; p++) {
            cin >> caixa;

            if (caixa == 1) {
               ans = tam[i]-p-1; //sempre remove as caixas acima de 1
               tam[i] = p+1;
               inv = i; //guarda qual pilha tem a caixa 1
            }
         }
      }

      int esq = 0;
      for (int j = inv-1; tam[j] >= tam[inv] && j >= 0; j--)
         esq += tam[j]-tam[inv]+1;

      int dir = 0;
      for (int j = inv+1; tam[j] >= tam[inv] && j < qtePilhas; j++)
         dir += tam[j]-tam[inv]+1;

      cout << min(ans+esq, ans+dir) << endl;
   }
   return 0;
}