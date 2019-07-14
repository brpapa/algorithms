/*
   ad-hoc
   problem: getline two-fruits
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int n, d, aluno;
   while (true) {
      cin >> n >> d;
      if (n == 0 && d == 0)
         return 0;

      vector<bool> participou(true, n);

      for (int j = 0; j < d; j++)
         for (int i = 0; i < n; i++) {
            cin >> aluno;
            if (aluno == 0)
               participou[i] = false;
         }

      bool achou = false;
      for (int i = 0; i < n && !achou; i++)
         if (participou[i] == true)
            achou = true;
      if (!achou)
         cout << "no" << endl;
      else
         cout << "yes" << endl;
   }
   return 0;
}
