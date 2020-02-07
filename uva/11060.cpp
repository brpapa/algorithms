/*
   graphs > traversal > topological sorting
   difficulty: easy
   problem: beverages
   date: 31/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
   int V, T = 0;
   while (cin >> V) {
      string str[110];
      map<string, int> id;
      vector<int> adjList[110];
      vector<int> inDegree(V, 0);

      for (int v = 0; v < V; v++) {
         cin >> str[v];
         id[str[v]] = v;
      }

      int E; cin >> E;
      while (E--) {
         string s1, s2; cin >> s1 >> s2;
         adjList[id[s1]].push_back(id[s2]);
         inDegree[id[s2]]++;
      }

      priority_queue<int> pq;
      for (int v = 0; v < V; v++) if (inDegree[v] == 0) pq.push(-v);

      printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
      while (!pq.empty()) {
         int v = 0-pq.top(); pq.pop();

         cout << " " << str[v];

         for (int u : adjList[v])
            if (--inDegree[u] == 0)
               pq.push(-u);
      }
      cout << "." << endl << endl;
   }
   return 0;
}