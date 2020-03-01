/*
   greedy > interval covering
   difficulty: medium
   problem: watering grass
   date: 15/Jan/2020
   solution: reduce the problem using pythagoras to one line
   author: @brnpapa
*/
#include <cmath>
#include <vector>
#include <iostream>  
#include <algorithm>
#define left first
#define right second
using namespace std;

vector<pair<double,double>> intervals;
 
int intervalCovering(double start, double end) {
   sort(intervals.begin(), intervals.end());

   int cnt = 0;
   double rightMost = start;

   for (int j, i = 0; i < intervals.size(); i = j) {
      if (intervals[i].left > rightMost) break;

      for (j = i + 1; j < intervals.size() && intervals[j].left <= rightMost; j++)
         if (intervals[j].right > intervals[i].right)
            i = j;
            
      cnt++;
      rightMost = intervals[i].right;

      if (rightMost >= end) break;
   }
   return (rightMost >= end)? cnt : -1;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int N, L, W;
   while (cin >> N >> L >> W) {
      intervals.clear();
      for (int i = 0; i < N; i++) {
         double x, r; cin >> x >> r;
         if (r > W/2.0) {
            double dx = sqrt(pow(r, 2) - pow(W/2.0, 2));
            intervals.push_back(make_pair(x-dx, x+dx));
         }
      }
      cout << intervalCovering(0.0, L) << endl;
   }
   return 0;
}