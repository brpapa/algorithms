#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
using namespace std;

const string CACHE_PATH = "_scripts/files-tracked-on-git.lock";

string replaceCh(string a, char b, char c) {
   //substitui b por c em a

   string r;
   for (int i = 0; i < a.size(); i++) {
      if (a[i] == b)
         r.push_back(c);
      else r.push_back(a[i]);
   }
   return r;
}

vector<string> separateTopics(string line) {
   vector<string> topics;
   
   int b;
   line.erase(0, 3); //remove tab

   while ((b = line.find(">")) != string::npos) {
      topics.push_back(line.substr(0, b-1));
      line.erase(0, b+2);
   }
   topics.push_back(line);
   return topics;
}