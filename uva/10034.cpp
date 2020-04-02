/*
   graphs > minimum spanning tree (MST)
   difficulty: easy
   date: 10/Nov/2019 
   by @brnpapa
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX_V 110
using namespace std;

struct Tedge {
   int v1, v2;
   double w;
   Tedge(int v1, int v2, double w) : v1(v1), v2(v2), w(w) {}
   bool operator<(const Tedge& e) const {
      return this->w < e.w;
   }
};
vector<Tedge> edgeList; // arestas não direcionadas

typedef pair<double,double> Tpoint;
Tpoint points[MAX_V]; // coordenada do vértice (first: x, second: y)

int p[MAX_V]; // ufds
int findSet(int i) {
   if (p[i] == i)
      return i;
   return p[i] = findSet(p[i]);
}

double distEuclidian(Tpoint c1, Tpoint c2) {
   return sqrt(pow(c1.first-c2.first, 2) + pow(c1.second-c2.second, 2));
}

int main() {
   int V, T;
   cin >> T;

   while (T--) {
      edgeList.clear();
      cin >> V;

      double x, y, d;
      for (int v = 0; v < V; v++) {
         cin >> x >> y;
         points[v] = make_pair(x, y);
         
         p[v] = v; // init ufds

         for (int t = 0; t < v; t++) { // para cada vértice t já lido
            d = distEuclidian(points[t], points[v]);
            edgeList.push_back(Tedge(t, v, d));
         }
      }

      double mstCost = 0;
      sort(edgeList.begin(), edgeList.end());

      for (Tedge e: edgeList) {
         int set_v1 = findSet(e.v1);
         int set_v2 = findSet(e.v2);

         if (set_v1 != set_v2) {
            p[set_v1] = set_v2; // union sets
            mstCost += e.w;
         }
      }

      printf("%.2lf%s", mstCost, (T == 0)?"\n":"\n\n");
   }
   return 0;
}