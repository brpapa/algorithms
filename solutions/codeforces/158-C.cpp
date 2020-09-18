/*
   ad-hoc > implementation
   difficulty: easy
   date: 09/Mar/2020 
   by: @brpapa
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N; cin >> N;
   vector<string> currAbsPath;

   while (N--) {
      string cmd; cin >> cmd;

      if (cmd == "pwd") {
         cout << "/";
         for (string dir : currAbsPath) cout << dir << "/"; 
         cout << endl;
      }
      else if (cmd == "cd") {
         string query; cin >> query;

         int l = 0;
         if (query[0] == '/') currAbsPath.clear(), l++;

         for (int r = l+1; r <= query.size(); r++)
            if (query[r] == '/' || r == query.size()) {
               string dir = query.substr(l, r-l);

               if (dir == "..") currAbsPath.pop_back();
               else currAbsPath.push_back(dir);

               l = r+1;
            }
      }
   }
   return 0;
}