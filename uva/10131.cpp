/*
   dynamic programming > longest increasing subsequence (LIS)
   difficulty: medium
   date: 25/Jan/2020 
   solution: sort elephants based on increasing kg, then apply LDS on iq
   by: @brnpapa
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct T {
   int id, kg, iq;
} e[1010];

bool cmp(const T &a, const T &b) {
   return a.kg < b.kg;
}

int N;
vector<int> memo, p;

// lds(j): tamanho da LDS terminando em e[j], olhando apenas para o iq
int lds(int j) {
   if (j == 0) return 1;

   int &ans = memo[j];
   if (ans != -1) return ans;

   ans = 1;
   for (int i = 0; i < j; i++)
      if (e[i].iq > e[j].iq && e[i].kg < e[j].kg && 1+lds(i) > ans) {
         ans = 1+lds(i);
         p[j] = i;
      }
   return ans;
}

void recover(int j) {
   if (j == -1) return;
   recover(p[j]);
   cout << e[j].id << endl;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
   for (N = 0; cin >> e[N].kg >> e[N].iq; N++) e[N].id = N+1;
   sort(e, e+N, cmp); // increasing kg

   memo.assign(N, -1); p.assign(N, -1);

   int ans = 1, end; // tamanho da lds ótima e onde termina
   for (int j = 0; j < N; j++)
      if (lds(j) >= ans) {
         ans = lds(j);
         end = j;
      }

   cout << ans << endl;
   recover(end);
   return 0;
}