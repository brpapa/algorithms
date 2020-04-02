/*
   graphs > traversal > depth-first search (DFS)
   difficulty: medium
   date: 28/Oct/2019 
   by @brnpapa
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_V 100010
using namespace std;

vector<int> adj[MAX_V];
int V, p[MAX_V];
bool arrested[MAX_V]; // mafioso preso

struct Theap {
   int id, qty; // quantos mafiosos não presos ele delata
   Theap(int id, int qty) {
      this->id = id;
      this->qty = qty;
   }
   bool operator<(const Theap &p) const {
      return this->qty < p.qty;
   }
};
priority_queue<Theap> heap;

void dfs(int v, int lvl) {
   if (adj[v].size() == 0) {
      heap.push(Theap(v, lvl));
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
   return 1 + qtyNotArrested(p[v]);
}

// marca mafiosos de v ao 1 como presos
void arrestAllSuperiors(int v) {
   if (arrested[v] || v == 0)
      return;
   arrested[v] = true;
   arrestAllSuperiors(p[v]);
}

int main() {
   int k, v;

   cin >> V >> k;
   for (int u = 2; u <= V; u++) {
      cin >> v;
      adj[v].push_back(u);
      p[u] = v;
   }
   p[1] = 0; // não existente
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
         heap.push(Theap(v, qtyCurr));
      }
   }
   cout << ans << endl;
   return 0;
}