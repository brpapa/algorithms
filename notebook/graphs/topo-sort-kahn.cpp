/*
   Topological sort - Kahn
   
   Motivação: dado um directed graph, encontre qualquer sequência linear de vértices, tal que, se nela u vem antes de v, existe um caminho u -> v. 
   
   ---
   Como é sempre priorizado o menor vértice em casos de não relação, há uma única solução.
*/
#include <bits/stdc++.h>
using namespace std;

/* input */
vector<vector<int>> adj_list; int V;

/* O(V+E) - retorna os vértices em ordem topológica */
vector<int> kahn() {

   vector<int> in_degree(V, 0);
   priority_queue<int> pq; // prioriza o menor vértice com in_degree atual 0

   for (int u = 0; u < V; u++) for (int v : adj_list[u]) in_degree[v]++;
   for (int u = 0; u < V; u++) if (in_degree[u] == 0) pq.push(-u);

   vector<int> ts;

   while (!pq.empty()) {
      int u = -pq.top(); pq.pop();
      ts.push_back(u);
      
      for (int v : adj_list[u])
         if (--in_degree[v] == 0)
            pq.push(-v);
   }

   return ts;
}
