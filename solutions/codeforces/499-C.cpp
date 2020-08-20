/*
   geometry
   difficulty: easy
   date: 12/Aug/2020
   hint: count how many lines the 2 points cross
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   ll xs,ys; cin >> xs >> ys;
   ll xt,yt; cin >> xt >> yt;

   ll N; cin >> N;
   ll ans = 0;

   while (N--) {
      ll a,b,c; cin >> a >> b >> c;

      // (xs,ys) e (xt,xt) estão em lados opostos da reta?
      ll s = a*xs + b*ys + c;
      ll t = a*xt + b*yt + c;
      if ((s > 0 && t < 0) || (s < 0 && t > 0))
         ans++;
   }

   cout << ans << endl;
	return 0;
}
