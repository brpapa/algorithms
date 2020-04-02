/*
   ad-hoc
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
using namespace std;

struct Coord {
   int x, y;
};
int main() {
   int n;
   Coord a, b, c;
   cin >> n >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

   string ans = "NO";
   if (b.x < a.x && c.x < a.x) {
      if (b.y < a.y && c.y < a.y)
         ans = "YES";
      else if (b.y > a.y && c.y > a.y)
         ans = "YES";
   }
   if (b.x > a.x && c.x > a.x) {
      if (b.y < a.y && c.y < a.y)
         ans = "YES";
      else if (b.y > a.y && c.y > a.y)
         ans = "YES";
   }
   cout << ans << endl;
   return 0;
}