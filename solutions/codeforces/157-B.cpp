/*
   geometry
   difficulty: none
   date: none 
   by: @brpapa
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
const double PI = acos(-1.0);
using namespace std;

int main() {
   int n, r;
   scanf("%d", &n);
   bool isRed = (n%2 == 1)? true : false;

   vector<int> raios;
   for (int i = 0; i < n; i++) {
      scanf("%d", &r);
      raios.push_back(r);
   }
   sort(raios.begin(), raios.end());

   double areaAnt = 0, area, ans = 0;
   for (int i = 0; i < n; i++, isRed = !isRed) {
      area = PI*raios[i]*raios[i];
      if (isRed)
         ans += area - areaAnt;
      areaAnt = area;
   }
   printf("%.10lf\n", ans);
   return 0;
}