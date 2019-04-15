#include <iostream>
using namespace std;

int main()
{
   int k, l, m, n;
   scanf("%d %d %d", &k, &l, &m);

   bool ganha[1000000];
   ganha[0] = false;
   for (int i = 1; i < 1000000; i++)
   {
      ganha[i] = true;
      if (!ganha[i - 1] || (!ganha[i - l] && i - l >= 0) || (!ganha[i - k] && i - k >= 0))
         continue;
      ganha[i] = false;
   }

   while (m--)
   {
      scanf("%d", &n);
      printf("%c", ganha[n] ? 'A' : 'B');
   }
   printf("\n");
   return 0;
}