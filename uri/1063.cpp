/*
   ad-hoc | stack
   problem: rails again... tracing movements
*/
#include <iostream>
#include <stack>
using namespace std;
#define MAX 26

int main() {
   int n, t, s;
   char entrada[MAX], saida[MAX];
   while (true) {
      cin >> n;
      if (n == 0)
         return 0;

      for (int i = 0; i < n; i++)
         cin >> entrada[i];
      for (int i = 0; i < n; i++)
         cin >> saida[i];

      stack<char> pilha;
      s = 0; //indice da saida
      for (int i = 0; i < n; i++) {
         cout << "I";
         pilha.push(entrada[i]);

         while (!pilha.empty() && pilha.top() == saida[s]) {
            cout << "R";
            pilha.pop();
            s++;
         }
      }
      printf("%s", (pilha.empty()) ? "\n" : " Impossible\n");
   }
}