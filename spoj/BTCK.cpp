/*
   backtracking | all permutations
   problem: a problem of backtracking
   author: @brnpapa
*/
#include <iostream>
using namespace std;
#define MAX 10

int a[MAX], solucao[MAX], perm[MAX], k;
bool usado[MAX], temSolucao;

void permuta(int perm[], int n) {
   //verifica se perm é uma solucao promissora
   int soma = 0;
   for (int i = 0; i < n; i++) {
      soma += perm[i] * a[i];
      if (soma > k)
         return; //descarta perm
   }

   if (n == MAX) { //solução válida
      for (int i = 0; i < MAX; i++)
         solucao[i] = perm[i];
      temSolucao = true;
      return;
   }
   for (int i = 0; i < MAX && !temSolucao; i++)
      if (!usado[i]) {
         usado[i] = true;
         perm[n] = i;
         permuta(perm, n + 1);
         usado[i] = false; //backtracking
      }
}

int main() {
   int t;
   cin >> t;
   while (t--) {
      for (int i = 0; i < MAX; i++) {
         cin >> a[i];
         //inicializa
         usado[i] = false;
      }
      cin >> k;

      temSolucao = false;
      permuta(perm, 0);
      if (!temSolucao)
         cout << -1 << endl;
      else {
         for (int i = 0; i < MAX - 1; i++)
            cout << solucao[i] << " ";
         cout << solucao[MAX - 1] << endl;
      }
   }
   return 0;
}