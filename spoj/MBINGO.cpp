/*
   ad-hoc | linear search
   problem: bingo!
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

bool chamouTodas(vector<bool> vet, int tam) {
   for (int i = 0; i < tam; i++)
      if (!vet[i])
         return false;
   return true;
}
int main() {
   int n, b, dif;
   while (true) {
      cin >> n >> b;
      if (n == 0 && b == 0)
         return 0;

      vector<int> bolas(b);
      vector<bool> ok(n+1, false);
      for (int i = 0; i < b; i++)
         cin >> bolas[i];

      ok[0] = true; //pode retirar as mesmas bolas, logo sempre terá uma dif abs nula
      for (int i = 0; i < b - 1; i++)
         for (int j = i + 1; j < b; j++)
            ok[abs(bolas[i] - bolas[j])] = true;

      printf("%s\n", chamouTodas(ok, n+1) ? "Y" : "N");
   }
}