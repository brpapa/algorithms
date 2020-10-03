/*
   Subset sum

   Motivação: dado um conjunto de números não-negativos, quantos subconjuntos com soma igual à S existem?


   Obs: Subset sum with repetition

      Motivação: dado N moedas com seus respectivos valores, quantos conjuntos distintos representam V centavos? Assume-se que há suprimento ilimitado de qualquer moeda.

      Basta alterar o subset sum para que lide com possíveis repetições. 
      Ficaria, então, na transição:  `return ans = dp(n+1, s) + dp(n, s-A[n]); // não considera A[n] e vai p/ o próximo, ou considera A[n] e não vai para o próximo (mantem-se)`
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

/* input */
const int N = 6;
const int S = 7;
int A[N] = {1, 3, 4, 5, 2, 10};

int memo[N][S+1];
int dp(int n, int s) {
   // n-ésimo número em A, soma S-s do subconjunto atual

   if (s == 0)          return 1;
   if (n == N || s < 0) return 0; // inválido

   int &ans = memo[n][s];
   if (ans != -1) return ans;

   return ans = dp(n+1, s) + dp(n+1, s-A[n]);
}

/* e.g. */
int main() {
   memset(memo, -1, sizeof memo); // resetar apenas se o array A mudar, e não S
   cout << dp(0, S) << endl;
}
