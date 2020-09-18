/*
   ad-hoc > implementation
   difficulty: easy
   date: 03/Dec/2019 
   by: @brpapa
*/
#include <cstdio>
using namespace std;

bool isNearlyLuckyNumber(int n) {
   if (n == 0)
      return false;
   while (n > 0) {
      int digit = n % 10;
      if (digit != 4 && digit != 7)
         return false;
      n /= 10;
   }
   return true;
}

int main() {
   char ch[20];
   scanf("%[0-9]\n", &ch);

   int numLuckyDigits = 0;
   for (int i = 0; ch[i] != '\0'; i++) {
      if (ch[i] == '4' || ch[i] == '7')
         numLuckyDigits++;
   }

   printf("%s\n", isNearlyLuckyNumber(numLuckyDigits) ? "YES" : "NO");
   return 0;
}