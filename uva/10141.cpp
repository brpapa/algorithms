/*
   ad-hoc
   difficulty: easy
   problem: request for proposal
   date: 17/Feb/2020
   author: @brnpapa
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct T {
   int idx;
   string name;
   double compliance, price;
   T() {}
};

// a < b
bool cmp(const T &a, const T &b) {
   if (a.compliance != b.compliance)
      return a.compliance > b.compliance;
   if (a.price != b.price)
      return a.price < b.price;
   return a.idx < b.idx;
}

int main() {
   int t = 1;
   while (true) {
      int R, P; cin >> R >> P >> ws; if (!R && !P) break;
      vector<string> requeriments(R);
      for (string &r : requeriments) getline(cin, r);

      vector<T> proposals(P); int p = 0;
      for (T &proposal : proposals) {
         proposal.idx = p++;

         getline(cin, proposal.name);
         double d, rMet; cin >> d >> rMet >> ws;

         proposal.price = d;
         proposal.compliance = (double)rMet/R;

         string trash;
         for (int r = 0; r < rMet; r++) getline(cin, trash);
      }
      sort(proposals.begin(), proposals.end(), cmp);

      if (t > 1) cout << endl;
      printf("RFP #%d\n%s\n", t++, proposals[0].name.c_str());
   }
   return 0;
}