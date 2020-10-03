/*
   geometry
   difficulty: easy
   date: 03/Oct/2020
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
   double x, y;
   Point() {}
   Point(double _x, double _y) : x(_x), y(_y) {}
   Point(const Point &P) : Point(P.x, P.y) {}

   bool operator==(const Point &O) { return x == O.x && y == O.x; }
   bool operator!=(const Point &O) { return !((*this) == O); }
   bool operator<(const Point &O) { return x != O.x ? (x < O.x) : (y < O.x); }

   Point operator-() { return Point(-x, -y); }
   Point operator+(const Point &O) { return Point(x + O.x, y + O.y); }
   Point operator-(const Point &O) { return Point(x - O.x, y - O.y); }
};

struct Vector : Point {
   Vector() {}
   Vector(double _x, double _y) : Point(_x, _y) {}
   Vector(Point P) : Point(P.x, P.y) {}
   Vector(Point P, Point Q) : Vector(Q-P) {}

   double norm() { return sqrt(x*x + y*y); }
   double norm2() { return x*x + y*y; }
};

Point translate(Point P, Vector V) {
   return Point(P.x + V.x, P.y + V.y);
}

Vector scale(Vector V, double k) {
   return Vector(V.x * k, V.y * k);
}

double dot(Vector V, Vector U) {
   return V.x*U.x + V.y*U.y;
}

double dist(Point P, Point Q) {
   return Vector(P, Q).norm();
}

double cross(Vector V, Vector U) {
   return V.x*U.y - V.y*U.x;
}

int orientation(Point P, Point Q, Point R) {
   double x = cross(Vector(P, Q), Vector(Q, R));
   if (x == 0) return 0;
   return (x > 0)? 1 : -1;
}

double dist_point_to_line(Point P, Point A, Point B) {
   if (A == B) throw invalid_argument("A and B should not be equals");

   Vector AP(A, P), AB(A, B);
   double u = dot(AP, AB)/AB.norm2();
   Point C = translate(A, scale(AB, u));
   return dist(P, C);
}

int main() {
   int T; cin >> T;
   while (T--) {
      double x, y; cin >> x >> y;
      double cx, cy, r; cin >> cx >> cy >> r;

      if (cx+r < x) { cout << "Goal!" << endl; continue; }

      double d1 = dist_point_to_line(Point(cx,cy), Point(x,y), Point(52.5, -3.66));
      double d2 = dist_point_to_line(Point(cx,cy), Point(x,y), Point(52.5, +3.66));

      if ((d1 > r && orientation(Point(x,y), Point(52.5, -3.66), Point(cx,cy)) == +1) 
       || (d2 > r && orientation(Point(x,y), Point(52.5, +3.66), Point(cx,cy)) == -1))
         cout << "Goal!" << endl;
      else cout << "No goal..." << endl;
   }
	return 0;
}
