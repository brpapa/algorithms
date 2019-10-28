/*
   graphs | depth first search (DFS)
   level: medium

   problem: denouncing mafia
   date: 28/Oct/2019
   author: @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_V 100010
using namespace std;

struct T {
   int id, qty; // quantos mafiosos não presos ele delata
   T(int id, int qty) {
      this->id = id;
      this->qty = qty;
   }
   bool operator<(const T &p) const {
      return this->qty < p.qty;
   }
};

vector<int> adj[MAX_V];
int V, pre[MAX_V]; // predecessor
bool arrested[MAX_V]; // mafioso preso
priority_queue<T> heap;

void dfs(int v, int lvl) {
   if (adj[v].size() == 0) {
      heap.push(T(v, lvl));
      return;
   }
   for (int i = 0; i < adj[v].size(); i++) {
      int u = adj[v][i];
      dfs(u, lvl+1);
   }
}

// quantos ainda não forem presos do mafioso v ao 1
int qtyNotArrested(int v) {
   if (arrested[v] || v == 0) // não existe mafioso 0
      return 0;
   return 1 + qtyNotArrested(pre[v]);
}

// marca mafiosos de v ao 1 como presos
void arrestAllSuperiors(int v) {
   if (arrested[v] || v == 0)
      return;
   arrested[v] = true;
   arrestAllSuperiors(pre[v]);
}

int main() {
   int k, v;

   cin >> V >> k;
   for (int u = 2; u <= V; u++) {
      cin >> v;
      adj[v].push_back(u);
      pre[u] = v;
   }
   pre[1] = 0; // não existente
   memset(arrested, false, sizeof(arrested));
   dfs(1, 1); // add nós folha na heap, com nivel

   int ans = 0;
   while (heap.size() > 0 && k > 0) {
      int v = heap.top().id;

      int qtyPrev = heap.top().qty;
      int qtyCurr = qtyNotArrested(v);
      heap.pop();
      
      if (qtyPrev == qtyCurr) {
         ans += qtyPrev;
         arrestAllSuperiors(v);
         k--;
      }
      else {
         heap.push(T(v, qtyCurr));
      }
   }
   cout << ans << endl;
   return 0;
}