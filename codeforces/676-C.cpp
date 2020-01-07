/*
   searching > two pointers
   difficulty: medium
   problem: vasya and strings
   date: 07/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<char> str;

int tp(char letter) {
   int maxLength = 0;
   int l = 0, r = 0;
   int k = 0; // mudanças gastas em [l .. r)

   for (; l < N; l++) {
      if (l > 0)
         k -= str[l - 1] != letter;

      for (; r < N && k <= K; r++)
         if (str[r] != letter)
            k++;
      if (k > K) {
         r--;
         k--;
      }

      // cout << l << " " << r << endl;
      maxLength = max(maxLength, r - l);
   }
   return maxLength;
}

int main() {
   cin >> N >> K;

   str.resize(N);
   for (char &s : str)
      cin >> s;

   cout << max(tp('a'), tp('b')) << endl;
   return 0;
}