/*
   greedy
   difficulty: medium
   date: 17/Apr/2020
   hint: sort the points, remove pairs with equal x and y first, then pairs with equal x and finally the rest
   by: @brpapa
*/
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int, bool> T;

int main() {
   int N; cin >> N;
   vector<T> points(N);

   for (int i = 0; i < N; i++) {
      int x, y, z; cin >> x >> y >> z;
      points[i] = make_tuple(x, y, z, i+1, 0);
   }

   sort(points.begin(), points.end());
   
   for (int k = 0; k <= 2; k++) {
      int prevx, prevy, previ = -1;
      vector<T>::iterator prevp;
      
      for (vector<T>::iterator p = points.begin(); p!= points.end(); p++) {
         if (get<4>(*p)) continue; // pois o ponto já foi removido logicamente

         int x = get<0>(*p), y = get<1>(*p), z = get<2>(*p);
         int i = get<3>(*p);

         if ((k <= 1? x == prevx: 1) && (k == 0? y == prevy: 1) && previ != -1) {
            cout << previ << " " << i << endl;

            get<4>(*(prevp)) = get<4>(*p) = 1;
            i = -1;
         }
         prevx = x, prevy = y, previ = i; prevp = p;
      }
   }
   return 0;
}