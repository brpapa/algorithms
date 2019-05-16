/*
   greedy | basic
   problem: palindrome lover
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ehPossivel(string str) {
   vector<int> freq(26, 0);
   for (int i = 0; i < str.size(); i++)
      freq[(int)str[i] - 97]++;

   int cont = 0;
   for (int i = 0; i < 26; i++) {
      if (freq[i] % 2 == 1)
         cont++;
      if (cont == 2)
         return -1;
   }
   return 1;
}

int main() {
   string str;
   while (getline(cin, str))
      cout << ehPossivel(str) << endl;
   return 0;
}