/*
   ad-hoc
   difficulty: easy
   date: 02/Mar/2020 
   by: @brpapa
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
   deque<int> dq;
   bool reversed = false;

   int Q; cin >> Q;
   while (Q--) {
      string cmd; cin >> cmd;

      if ((cmd == "back" && !reversed) || (cmd == "front" && reversed)) {
         if (dq.empty()) cout << "No job for Ada?" << endl;
         else { cout << dq.back() << endl; dq.pop_back(); }
      }
      else if ((cmd == "front" && !reversed) || (cmd == "back" && reversed)) {
         if (dq.empty()) cout << "No job for Ada?" << endl;
         else { cout << dq.front() << endl; dq.pop_front(); }
      }

      else if (cmd == "reverse") {
         reversed = !reversed;
      }

      else if ((cmd == "push_back" && !reversed) || (cmd == "toFront" && reversed)) {
         int n; cin >> n; dq.push_back(n);
      }
      else if ((cmd == "toFront" && !reversed) || (cmd == "push_back" && reversed)) {
         int n; cin >> n; dq.push_front(n);
      }
   }
   return 0;
}