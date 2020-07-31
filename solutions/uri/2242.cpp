/*
   ad-hoc
   difficulty: easy
   date: 16/Mar/2019 
   by: @brnpapa
*/
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
   return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
bool isFunny(string str) {
   int j = 0;
   char aux[50];
   for (int i = 0; i < str.size(); i++)
      if (isVowel(str[i]))
         aux[j++] = str[i];

   j = 0;
   for (int i = str.size() - 1; i >= 0; i--)
      if (isVowel(str[i]))
         if (str[i] != aux[j++])
            return false;

   return true;
}

int main() {
   string str;
   cin >> str;
   printf("%s\n", isFunny(str) ? "S" : "N");
   return 0;
}