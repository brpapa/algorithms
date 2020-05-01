/*
   dynamic programing > digit
   difficulty: easy
   date: 01/May/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> digs; 
ll memo[10][9*10+1][2];
ll dp(int i, int sum, bool limited) {
   // dígito atual digs[i], soma acumulada sum
   // se limited, dígito atual pode variar de 0 à digs[i], se não, de 0 à 9

   if (i == digs.size()) return sum;

   ll &ans = memo[i][sum][limited];
   if (ans != -1) return ans;

   ans = 0;
   for (int d = 0; d <= (limited? digs[i]: 9); d++)
      ans += dp(i+1, sum+d, d == digs[i]? limited: 0 );

   return ans;
}

// retorna a soma dos dígitos dos números em [1 .. n]
ll solve(int n) {
   // se n = 250, digs = {2, 5, 0}
   digs.clear();
   while (n > 0) digs.push_back(n % 10), n /= 10;
   reverse(digs.begin(), digs.end());

   memset(memo, -1, sizeof memo);
   return dp(0, 0, 1);
}

int main() {
   int a, b;
   while (cin >> a >> b && !(a == -1 && b == -1))
      cout << solve(b) - solve(a-1) << endl;

   return 0;
}
