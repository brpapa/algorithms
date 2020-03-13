#include <iostream>
#include <cmath>
using namespace std;

namespace CG {
   const double EPS = 1e-9; // epsilon (erro satisfatório)

   // a == b?
   bool isEqual(double a, double b) { return abs(a-b) < EPS; }
   // a == 0?
   bool is0(double a) { return isEqual(a, 0.0); }
   // a > 0?
   bool isgt0(double a) { return a > 0+EPS; }
   // a < 0?
   bool islt0(double a) { return a < 0-EPS; }


   struct Point {
      double x, y; // coordenadas em relação à origem (0, 0)
      Point(double _x, double _y) : x(_x), y(_y) {}

      // *this == P?
      bool operator==(const Point &P) const { return isEqual(this->x, P.x) && isEqual(this->y, P.x); }
      // *this != P?
      bool operator!=(const Point &P) const { return !(*this == P); }
      // *this < P?
      bool operator<(const Point &P) const { return !isEqual(this->x, P.x) ? (x < P.x) : (y < P.x); }
   };
   // oposto do ponto
   Point operator-(const Point &P) { return Point(-P.x, -P.y); }
   // adição e substração de pontos
   Point operator+(const Point &P1, const Point &P2) { return Point(P1.x+P2.x, P1.y+P2.y); }
   Point operator-(const Point &P1, const Point &P2) { return P1+(-P2); }

   // debug
   ostream &operator<<(ostream &os, const Point &P) { return os << "(" << P.x << "," << P.y << ")"; }


   struct Line {
      double a, b, c; // coeficientes na equação a*x + b*y + c = 0

      Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
      Line(Point P1, Point P2) {
         if (isEqual(P1.x, P2.x)) // reta vertical, fixando b em 0
            *this = Line(1.0, 0.0, -P1.x);
         else {                   // reta não-vertical, fixando b em 1
            this->a = -(P1.y-P2.y) / (P1.x-P2.x);
            this->b = 1.0;
            this->c = -(this->a * P1.x) - P1.y;
         }
      }
   }; 


   struct Vector {
      //> não se trata de uma posição específica (como Point), é sempre em relação à origem (0, 0)
      double x, y;
      Vector(double _x, double _y) : x(_x), y(_y) {}
      // converte o ponto P para um vetor (0,0) -> (P.x, P.y)
      Vector(Point P) { *this = Vector(P.x, P.y); }
      // converte dois pontos para um vetor
      Vector(Point P1, Point P2) { *this = Vector(P2 - P1); }

      // retorna a norma/magnitude do vetor (|V|)
      double norm() {
         return sqrt(pow(this->x, 2) + pow(this->y, 2));
      }
      // retorna o quadrado da norma/magnitude do vetor
      double norm2() {
         return pow(this->x, 2) + pow(this->y, 2);
      }

      // *this == V?
      bool operator==(const Vector &V) const { return isEqual(this->x, V.x) && isEqual(this->y, V.x); }
      // *this != V?
      bool operator!=(const Vector &V) const { return !(*this == V); }
      // *this < V?
      bool operator<(const Vector &V) const { return !isEqual(this->x, V.x)? (x < V.x) : (y < V.x); }
   };
   // oposto do vetor
   Vector operator-(const Vector &V) { return Vector(-V.x, -V.y); }
   // adição e substração de vetores
   Vector operator+(const Vector &V1, const Vector &V2) { return Vector(V1.x+V2.x, V1.y+V2.y); }
   Vector operator-(const Vector &V1, const Vector &V2) { return V1+(-V2); }

   // translate: move o ponto
   Point translate(Point P, Vector V) { return Point(P.x + V.x, P.y + V.y); }
   // scale: multiplica o vetor por uma constante //! não-negativa
   Vector scale(Vector V, double k) { return Vector(V.x * k, V.y * k); }
   // V1.V2: produto escalar entre vetores
   double dot(Vector V1, Vector V2) { return V1.x*V2.x + V1.y*V2.y; }
   // V1xV2: produto vetorial entre vetores
   double cross(Vector V1, Vector V2) { return V1.x*V2.y - V1.y*V2.x; }

   ostream &operator<<(ostream &os, const Vector &V) { return os << "(" << V.x << "," << V.y << ")"; }


   // retorna deg (dado em graus) em radianos
   double radian(double deg) {
      return deg*(M_PI/180.0);
   }
   // retorna rad (dado em radianos) em graus
   double degree(double rad) {
      return rad*(180.0/M_PI);
   }

   // retorna o ponto P rotacionado em deg graus no sentido anti-horário em relação à origem (0, 0)
   Point rotate(Point P, double deg) {
      double rad = radian(deg);
      return Point(P.x*cos(rad) - P.y*sin(rad), P.x*sin(rad) + P.y*cos(rad));
   }

   bool areParallel(Line L1, Line L2) {
      // importante ter fixado b em 0 ou 1 ao definir a reta
      return isEqual(L1.a, L2.a) && isEqual(L1.b, L2.b);
   }
   bool areSame(Line L1, Line L2) {
      return areParallel(L1, L2) && isEqual(L1.c, L2.c);
   }

   // retorna o ponto de intersecção entre retas //! não-paralelas
   Point intersectPoint(Line L1, Line L2) {
      // resolve o sistema linear entre L1.a*x + L1.b*y + L1.c = 0 e L2.a*x + L2.b*y + L2.c = 0
      // a, b ou c de cada Line podem ser 0
      int x = (L2.b*L1.c - L1.b*L2.c) / (L2.a*L1.b - L1.a*L2.b);
      int y = !is0(L1.b) ? -(x*L1.a + L1.c) : -(x*L2.a + L2.c); // evita divisão por zero
      return Point(x, y);
   }

   // retorna a projeção escalar de V1 em V2
   double scalarProjection(Vector V1, Vector V2) {
      //! re-estudar
      return dot(V1, V2)/V2.norm2();
   }

   // retorna a distância euclidiana entre pontos
   double distPointToPoint(Point P1, Point P2) {
      return Vector(P1, P2).norm();
   }

   // retorna a distância de P para a reta definida pelos pontos A e B //! não-iguais
   double distPointToLine(Point P, Point A, Point B) {
      Vector AP(A, P), AB(A, B);
      double u = scalarProjection(AP, AB);
      Point C = translate(A, scale(AB, u)); // ponto na reta mais perto (perpendicular) de P
      return distPointToPoint(P, C);
   }

   // retorna a distância mínima de um ponto P para um segmento de reta de A à B
   double distPointToLineSegment(Point P, Point A, Point B) {
      Vector AP(A, P), AB(A, B);
      double u = scalarProjection(AP, AB);

      if (u < 0.0) return distPointToPoint(P, A); // P está mais perto de A
      if (u > 1.0) return distPointToPoint(P, B); // P está mais perto de B
      return distPointToLine(P, A, B);
   }

   // retorna o ângulo entre os pontos A, O e B em radianos
   double angle(Point A, Point O, Point B) {
      // OA.OB = |OA|*|OB|*cos(theta) => theta = acos(OA.OB / |OA|*|OB|)
      Vector OA(O, A), OB(O, B);
      return acos(dot(OA, OB) / sqrt(OA.norm2() * OB.norm2()));
   }

   // o ponto P está ao lado esquerdo da reta definida por Q e R? (counter clockwise test, CCW)
   bool isLeft(Point P, Point Q, Point R) {
      return isgt0(cross(Vector(P, Q), Vector(P, R)));
   }
   // o ponto P está na reta definida por Q e R?
   bool isCollinear(Point P, Point Q, Point R) {
      return is0(cross(Vector(P, Q), Vector(P, R)));
   }
}
using namespace CG;

int main() {
   
}