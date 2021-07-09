/*
   math > number theory
   difficulty: medium
   date: 15/Jun/2020
   problem: find the longest DDF sequence
   hint: pre-process a array f, where f[i] is the sum of digits of all positive factors of i; think like sieve
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 3030

int f[MAX];

int sumDigits(int n) {
	int sum = 0;
	while (n > 0) sum += n%10, n /= 10;
	return sum;
}

int memo[MAX];  // memo[n] = tamanho da sequencia que inicia com n
int dp(int n) {
	int &ans = memo[n];
	if (ans != -1) return ans;

	if (n == f[n]) return 1;
	return ans = 1 + dp(f[n]);
}

int main() {
   for (int i = 0; i <= MAX; i++) f[i] = 1;
	for (int i = 2; i <= MAX; i++) {
      int sum = sumDigits(i);
      for (int j = i; j <= MAX; j += i) f[j] += sum;
   }
	
	memset(memo, -1, sizeof memo);

	int m, n; int t = 1;
	while (cin >> m >> n) {
      int lo = min(m, n);
      int hi = max(m, n);

		int maxLen = 0;
		int start = hi;

		for (int i = hi; i >= lo; i--)
			if (dp(i) >= maxLen) {
				maxLen = dp(i);
				start = i;
			}
		
		printf("Input%d: %d %d\n", t, m, n);
		printf("Output%d: ", t++);
		for (int i = start; true; i = f[i]) {
         if (i == f[i]) { cout << i << endl; break; }
         cout << i << " ";
      }
	}

	return 0;
}
