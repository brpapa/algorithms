/*
   geometry
   difficulty: easy
   date: 25/Jun/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

double circleArea(double r) {
   return M_PI*r*r;
}
double triangleArea(double a, double b, double c) {
   double sp = (a+b+c)/2; // semi perimeter
   return sqrt(sp*(sp-a)*(sp-b)*(sp-c));
}

int main() {
   double a, b, c;
   while (cin >> a >> b >> c) {
      double triangle = triangleArea(a,b,c);
      double inCircle = circleArea(triangle/((a+b+c)/2));
      double circumCircle = circleArea(a*b*c/(4*triangle));

      printf("%.4lf %.4lf %.4lf\n", circumCircle-triangle, triangle-inCircle, inCircle);
   }
	return 0;
}
