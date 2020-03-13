/*
   techniques > two pointers
   difficulty: easy
   problem: alice, bob and chocolate
   date: 09/Jan/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   int N;
   cin >> N;

   vector<int> tn(N); // time needed
   for (int &t : tn)
      cin >> t;

   int a = 0, b = N-1; // barra atual de alice, de bob (a que estão comendo)

   while (a <= b) {
      if (tn[a] <= tn[b] && a != b-1)
         tn[b] -= tn[a++];
      else
         tn[a] -= tn[b--];
   }
   cout << a << " " << N-1 - b << endl;
   return 0;
}