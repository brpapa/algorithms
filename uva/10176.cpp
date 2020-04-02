/*
   math > number theory > module arithmetic
   difficulty: easy
   date: 20/Mar/2020
   problem: is a given binary number of 100 digits divisible by 131071?
   by @brnpapa
*/
#include <iostream>
#include <vector>
#define ll long long
#define MOD 131071
using namespace std;

int main() {
   vector<char> bin;
   string str;

   while (cin >> str) {
      bin.clear(); for (char c : str) if (c != '#') bin.push_back(c);
      while (str.back() != '#') {
         cin >> str;
         for (char c : str) if (c != '#') bin.push_back(c);
      };
      int N = bin.size();

      // input em bin, de tamanho N

      ll sum = 0;
      for (int i = 0; i < N; i++) {
         if (bin[i] == '0') continue;

         // p = 2^(N-i-1)
         ll p = 1; 
         int K = N-i-1; while (K--) p = (2*p)%MOD;
         p %= MOD;

         sum = (sum+p)%MOD;
      }
      sum %= MOD;
      cout << (sum == 0? "YES":"NO") << endl;
   }
   return 0;
}
