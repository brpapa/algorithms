/*
   greedy > two pointers
   difficulty: easy
   problem: sereja and dima
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

   vector<int> cards(N);
   for (int &c : cards)
      cin >> c;

   int sPts = 0, dPts = 0;

   int l, r = N-1;
   while (l <= r) {
      // s turn
      sPts += (cards[l] > cards[r])? cards[l++] : cards[r--];

      // d turn
      if (l <= r)
         dPts += (cards[l] > cards[r])? cards[l++] : cards[r--];
   }
   cout << sPts << " " << dPts << endl;
   return 0;
}