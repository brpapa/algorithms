/*
   dynamic programming > digit
   difficulty: medium
   date: 08/Sep/2019 
   problem: given two numbers x and y, compute the sum of the decimal digits of the odd numbers in the range [min(x,y) .. max(x,y)]
   by: @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

ll memo[10][9*10+1]; // índices, soma de 999999999

vector<int> digits;  // = {0,2,1,3} para 3120

void setDigits(ll n) {
   digits.clear();
   while (n > 0)
      digits.push_back(n % 10), n /= 10;
}

// retorna a soma dos dígitos de 1 ao inteiro representado por digits
ll dp(int i, int sum, bool limited) {
   // dígito atual digits[i] com soma acumulada sum
   // limited = true  -> dígito atual varia de 0 à digits[i]
   // limited = false -> dígito atual varia de 0 à 9

   if (i == -1) return sum;

   ll &ans = memo[i][sum];
   if (ans != -1 && !limited) return ans; // casos restritos não são memorizados

   ll tmp = 0;
   for (int d = 0; d <= (limited? digits[i] : 9); d++) {
      if (i == 0 && d % 2 == 0) continue; // última casa decimal par

      tmp += dp(
         i - 1,                             // próximo dígito menos significativo
         sum + d,                           // soma anterior + dígito gerado
         d == digits[i]? limited : false   // se d gerado é igual ao dígito do indice atual, o próximo estado é restrito desde que o atual já seja 
      );
   }
   return limited? tmp : (ans = tmp);
}

int main() {
   ll x, y, nmin, nmax, smin, smax;
   memset(memo, -1, sizeof(memo));

   while (cin >> x >> y) {
      nmin = min(x, y);
      nmax = max(x, y);

      setDigits(nmin-1); smin = dp(digits.size()-1, 0, 1); // soma de 1 à nmin-1
      setDigits(nmax);   smax = dp(digits.size()-1, 0, 1); // soma de 1 à nmax

      cout << smax - smin << endl;
   }
   return 0;
}