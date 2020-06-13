/*
   math > number theory > prime numbers > sieve of eratosthenes
   difficulty: easy
   date: 08/Jun/2020
   problem: check if a large n has exactily three distinct positive divisors
   hint: check if sqrt(n) is prime
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
2^2 =  4 = 1 2 4
3^2 =  9 = 1 3 9
5^2 = 25 = 1 5 25
7^2 = 49 = 1 7 49
*/

#define UB 1000000 // sqrt(10^12)
bitset<UB+1> isPrime;

void sieve() {
	isPrime.set(); isPrime[0] = isPrime[1] = 0;

	for (ll i = 2; i <= UB; i++)
		if (isPrime[i])
			for (ll j = i*i; j <= UB; j += i) isPrime[j] = 0;
}

int main() {
   sieve();
   int N; cin >> N;
   while (N--) {
      ll n; cin >> n;
      double sn = sqrt(n);
      if (sn == (double)(int)sn && (isPrime[(int)sn]))
         cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   return 0;
}