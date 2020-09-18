/*
   math > ad-hoc > sequences
   difficulty: hard
   date: 31/Mar/2020
   hint: pre-process the number sequence and f(k), so use binary search on f
   by: @brpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define MAX_K ((int)1e5) // pois f[MAX_K] > max i
#define MAX_N ((int)5e5) // maior que f[MAX_K-1]-f[MAX_K-2]
using namespace std;

// total de digitos do grupo Sk = [1, 2, ..., k]
ll g(ll k) {
   ll ans = 0;
   
   for (int i = 0; true; i++) {
      ll p = pow(10, i)-1;
      if (k <= p) return ans;

      ans += (i+1) * (min(k, (ll)pow(10,i+1)-1) - p);
   }
   return -1;
}

vector<int> digs(int n) {
   vector<int> ans;
   while (n > 0) {
      ans.insert(ans.begin(), n%10);
      n /= 10;
   }
   return ans;
}

int main() {
   // numSeq: [0, 1, ..., 9, 1, 0, 1, 1, 1, 2, ...]
   vector<int> numSeq(1, 0);
   for (int n = 1; n < MAX_N; n++) for (int d : digs(n)) numSeq.push_back(d);

   // f[k]: índice do número 1 no k-ésimo grupo (k >= 1)
   vector<ll> f(MAX_K); f[1] = 1;
   for (int k = 2; k < MAX_K; k++) f[k] = f[k-1]+g(k-1);


   int T; cin >> T;
   while (T--) {
      int i; cin >> i;
      
      // i-ésimo número está no grupo k
      int k = upper_bound(f.begin(), f.end(), i) - f.begin()-1;

      int n = i-(f[k]-1); // i em relação à f[k] >= 1
      cout << numSeq[n] << endl;
   }
   return 0;
}
