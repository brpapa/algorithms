/*
   backtracking | path
   problem: spiky mazes
*/
#include <iostream>
using namespace std;

char mapa[41][41];
bool posVerificada[41][41], ok = false;
int n, m, maxEspinhos;

bool posValida(int l, int c) {
   return (l >= 0 && l < n && c >= 0 && c < m && mapa[l][c] != '#');
}
//considerando o tesouro ('x') como posição inicial, percorre até a saída ('@')
void anda(int l, int c, int espinhos) {
   if (mapa[l][c] == '@') {
      ok = true;
      return;
   }
   if (mapa[l][c] == 's') {
      espinhos++;
      if (espinhos * 2 > maxEspinhos) //dobro de espinhos pois tem que ir e voltar
         return;
   }

   //para cada possível lado, tenta andar
   if (!ok && posValida(l - 1, c) && !posVerificada[l - 1][c]) {
      posVerificada[l - 1][c] = true;
      anda(l - 1, c, espinhos);
      posVerificada[l - 1][c] = false;
   }
   if (!ok && posValida(l, c + 1) && !posVerificada[l][c + 1]) {
      posVerificada[l][c + 1] = true;
      anda(l, c + 1, espinhos);
      posVerificada[l][c + 1] = false;
   }
   if (!ok && posValida(l + 1, c) && !posVerificada[l + 1][c]) {
      posVerificada[l + 1][c] = true;
      anda(l + 1, c, espinhos);
      posVerificada[l + 1][c] = false;
   }
   if (!ok && posValida(l, c - 1) && !posVerificada[l][c - 1]) {
      posVerificada[l][c - 1] = true;
      anda(l, c - 1, espinhos);
      posVerificada[l][c - 1] = false;
   }
}

int main() {
   int l, c;
   cin >> n >> m >> maxEspinhos;
   for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < m; j++) {
         mapa[i][j] = str[j];
         if (mapa[i][j] == 'x') {
            l = i;
            c = j;
         }
         posVerificada[i][j] = false;
      }
   }
   anda(l, c, 0); //numero de espinhos evitados inicia com 0
   printf("%s\n", ok ? "SUCCESS" : "IMPOSSIBLE");
   return 0;
}