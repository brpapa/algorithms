/*
   dynamic programming | digits
   problem: numbers game
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

ll memo[10][9*10+1]; //índices, soma de 999999999
vector<int> digits; // = {0,2,1,3} para 3120

void getDigits(ll n) {
   digits.clear();
   while (n > 0) {
      digits.push_back(n % 10);
      n /= 10;
   } 
}

//retorna a soma dos dígitos de 1 ao inteiro representado por digits
ll dpTD(int idx, int sum, bool tight) {
   //estado: dígito atual digits[idx] com soma acumulada sum

   //tight = false -> dígito atual é restrito (dig varia de 0 à digits[idx])
   //tight = true  -> dígito atual não é restrito (dig varia de 0 à 9)

   if (idx == -1)
      return sum;

   ll &m = memo[idx][sum];
   if (m != -1 && !tight) return m; //casos restritos não são memorizados

   ll ans = 0;
   for (int dig = 0; dig <= (tight? digits[idx] : 9); dig++) {
      if (idx == 0 && dig % 2 == 0)
         continue; //última casa decimal par

      ans += dpTD(
         idx - 1,                            //próximo dígito menos significativo
         sum + dig,                          //soma anterior + dígito gerado
         dig == digits[idx]? tight : false   //se dig gerado é igual ao dígito do indice atual, o próximo estado é restrito desde que o atual já seja 
      );
   }

   return tight? ans : (m = ans);
}

int main() {
   ll x, y, nmin, nmax, smin, smax;
   memset(memo, -1, sizeof(memo));

   while (cin >> x >> y) {
      nmin = min(x, y);
      nmax = max(x, y);

      getDigits(nmin - 1);
      smin = dpTD(digits.size()-1, 0, true); //soma de 1 à nmin-1

      getDigits(nmax);
      smax = dpTD(digits.size()-1, 0, true); //soma de 1 à nmax

      cout << smax - smin << endl;
   }
   return 0;
}