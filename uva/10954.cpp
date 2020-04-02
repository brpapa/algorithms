/*
   ad-hoc
   difficulty: none
   date: none 
   by @brnpapa
/*
#include <iostream>
#include <queue>
using namespace std;

int main() {
   int n, aux;
   while (true) {
      cin >> n;
      if (n == 0)
         return 0;

      priority_queue<int> heap;
      for (int i = 0; i < n; i++) {
         cin >> aux;
         heap.push(-aux);
      }

      int custo = 0;
      while (!heap.empty()) {
         int tmp1 = -heap.top();
         heap.pop();
         if (heap.empty())
            break;
         int tmp2 = -heap.top();
         heap.pop();
         custo += tmp1 + tmp2;
         heap.push(-tmp1 - tmp2);
      }
      cout << custo << endl;
   }
}