#include <iostream>
using namespace std;

int main()
{
   long long int n;
   scanf("%lld", &n);

   int moedas[5] = {100, 20, 10, 5, 1}, qte = 0;
   for (int i = 0; n > 0; i++)
      while (n >= moedas[i])
      {
         n -= moedas[i];
         qte++;
      }
   printf("%d\n", qte);
   return 0;
}