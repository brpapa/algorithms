// dynamic programming: minimax
#include <iostream>
#include <vector>
#define ALBERTO 0
#define WANDERLEY 1
using namespace std;

long long int memo[10000][10000];
int seq[10000];

//retorna a pontuação que o jogador da vez pode obter de seq[e] até seq[d]
long long int pts(int e, int d, int jogador)
{
   if (d - e < 0)
      return 0;

   if (memo[d][e] == -1) //ainda não calculado
   {
      if (jogador == ALBERTO)
         memo[d][e] = max(
            (long long int)seq[e] + pts(e + 1, d, WANDERLEY), //ALBERTO remove esq
            (long long int)seq[d] + pts(e, d - 1, WANDERLEY)  //ALBERTO remode dir
         );
      else
         memo[d][e] = min(
               pts(e + 1, d, ALBERTO), //WAND remove esq
               pts(e, d - 1, ALBERTO)  //WAND remode dir
         );
   }
   return memo[d][e];
}

int main()
{
   int n;
   while (scanf("%d", &n) != EOF)
   {
      for (int i = 0; i < n; i++)
      {
         scanf("%d", &seq[i]);
         for (int j = 0; j <= i; j++)
            memo[i][j] = -1;
      }
      printf("%lld\n", pts(0, n - 1, ALBERTO));
   }
   return 0;
}