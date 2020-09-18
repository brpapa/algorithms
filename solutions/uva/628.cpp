/*
   brute force > iterative
   difficulty: easy
   date: 14/Apr/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

// retorna o d-ésimo dígito de num, sendo o 0-ésimo dígito aquele mais à direta
int dig(int num, int d) {
   while (d--) num /= 10;
   return num % 10;
}

int main() {
   int N;
   while (cin >> N) {
      vector<string> words(N);
      for (string &word : words) cin >> word;

      cout << "--" << endl;
      int M; cin >> M; 
      while (M--) {
         string rule; cin >> rule;
         int count0 = 0; for (char c : rule) if (c == '0') count0++;

         for (string word : words) {
            for (int num = 0; num < pow(10, count0); num++) {

               int d = count0-1;
               for (char c : rule) {
                  if (c == '0') cout << dig(num, d--);
                  else cout << word;
               }
               cout << endl;
            }
         }
      }
   }
   return 0;
}
