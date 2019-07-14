/*
   ad-hoc
   problem: i can guess the data structure!
   author: @brnpapa
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
   int n, tmp, op;
   pair<int, int> dados[1001];
   bool ehStack, ehQueue, ehPriorityQueue;

   while (scanf("%d", &n) != EOF) {
      for (int i = 0; i < n; i++) {
         scanf("%d %d", &op, &tmp);
         dados[i] = make_pair(op, tmp);
      }
      ehStack = true;
      stack<int> p;
      for (int k = 0; k < n && ehStack; k++) {
         if (dados[k].first == 1)
            p.push(dados[k].second);
         else {
            if (dados[k].second != p.top())   
               ehStack = false;
            else p.pop();
         }
      }
      ehQueue = true;
      queue<int> q;
      for (int k = 0; k < n && ehQueue; k++) {
         if (dados[k].first == 1)
            q.push(dados[k].second);
         else {
            if (dados[k].second != q.front())   
               ehQueue = false;
            else q.pop();
         }
      }
      ehPriorityQueue = true;
      priority_queue<int> pq;
      for (int k = 0; k < n && ehPriorityQueue; k++) {
         if (dados[k].first == 1)
            pq.push(dados[k].second);
         else {
            if (dados[k].second != pq.top())   
               ehPriorityQueue = false;
            else pq.pop();
         }
      }
      if (ehStack && !ehQueue && !ehPriorityQueue)
         printf("stack\n");
      else if (!ehStack && ehQueue && !ehPriorityQueue)
         printf("queue\n");
      else if (!ehStack && !ehQueue && ehPriorityQueue)
         printf("priority queue\n");
      else if (!ehStack && !ehQueue && !ehPriorityQueue)
         printf("impossible\n");
      else
         printf("not sure\n");
   }
   return 0;
}