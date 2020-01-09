/*
   greedy > maximum subsequence
   problem: ilya and queries
   author: @brnpapa
*/
#include <iostream>
using namespace std;

int main() {
   int m, l, r, soma[100001];
   string str;
   cin >> str >> m;

   soma[1] = 0; //pré processamento
   for (int i = 1; i < str.length(); i++) {
      soma[i+1] = soma[i];
      if (str[i] == str[i-1])
         soma[i+1]++;
   }

   while (m--) {
      scanf("%d %d", &l, &r);
      printf("%d\n", soma[r] - soma[l]);
   }
   return 0;
}