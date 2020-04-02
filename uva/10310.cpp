/*
   computational geometry
   difficulty: none
   date: none 
   by @brnpapa
*/
#include <iostream>
#include <vector>
#include <cmath>
#define X first
#define Y second
using namespace std;

typedef pair<double, double> TPoint;

double distPoints(TPoint a, TPoint b){
   return sqrt((a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y));
}

int main() {
   int qteBuracos;
   double tmpX, tmpY, distCachorro, distTopeira;
   TPoint t0, c0, ans; //topeira, cachorro
   vector<TPoint> buracos;

   while (scanf("%d", &qteBuracos) != EOF) {
      scanf("%lf %lf", &t0.X, &t0.Y);
      scanf("%lf %lf", &c0.X, &c0.Y);
      buracos.clear();
      for (int i = 0; i < qteBuracos; i++) {
         scanf("%lf %lf", &tmpX, &tmpY);
         buracos.push_back(make_pair(tmpX, tmpY));
      }

      bool topeiraEscapa = false;
      for (int i = 0; i < qteBuracos && !topeiraEscapa; i++) {
         distTopeira = distPoints(t0, buracos[i]);
         distCachorro = distPoints(c0, buracos[i]);

         if (distCachorro/2.0 >= distTopeira) {
            topeiraEscapa = true;
            ans = buracos[i];
         }
      }

      if (topeiraEscapa)
         printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", ans.X, ans.Y);
      else printf("The gopher cannot escape.\n");
   }
   return 0;
}