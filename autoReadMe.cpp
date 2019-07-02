// header padrão de todo .cpp:
/*
   theme | topic1 | topic2
   problem: name
*/
// não usar subtópicos idênticos!!!
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

//árvore de strings, sendo "root" o nó raiz
map<string, set<string> > graph;
map<string, int> level;

map<string, string> url; //const

void initJudgeURLs() {
   url["codeforces"] = "https://vjudge.net/problem/codeforces-";
   url["spoj"] = "https://spoj.com/problems/";
   url["uri"] = "https://www.urionlinejudge.com.br/judge/problems/view/";
   url["uva"] = "https://vjudge.net/problem/uva-";
   url["leetcode"] = "https://leetcode.com/problems/";
}

void separateTopics(string line, vector<string> &topics) {
   int b;
   topics.clear();
   line.erase(0, 3); //remove tab

   while ((b = line.find("|")) != string::npos) {
      topics.push_back(line.substr(0, b-1));
      line.erase(0, b+2);
   }
   topics.push_back(line);
}
void readCppFile(string folder, string file) {
   string line;
   vector<string> topics;
   ifstream in(folder+"/"+file+".cpp");

   getline(in, line); // /*

   getline(in, line); // theme | topic1 | topic2
   separateTopics(line, topics);

   graph["root"].insert(topics.front());
   for (int i = 0; i < topics.size()-1; i++)
      graph[topics[i]].insert(topics[i+1]);

   getline(in, line); // problem: name
   line.erase(0, 12); 

   string linkToMySolution = "[" + folder + "/" + file + "](https://github.com/brnpapa/judge-solutions/blob/master/" + folder + "/" + file + ".cpp)";
   string linkToProblemURL = "[" + line + "](" + url[folder] + file + ")";

   graph[topics.back()].insert(linkToMySolution + " ⇢ " + linkToProblemURL);
   in.close();
}
void readAllCppFilesTrackedOnGit() {
   string line;
   system("git ls-files > tmp.bat"); 

   ifstream in("tmp.bat");
   while (!in.eof()) {
      getline(in, line);
      if (line.find(".cpp") == string::npos || line == "autoReadMe.cpp")
         continue; //line não contém ".cpp"

      int b = line.find("/"), p = line.find(".");
      readCppFile(
         line.substr(0, b), //folder
         line.substr(b+1, p-b-1) //file without .cpp
      );
   }
   in.close();
   system("rm -f tmp.bat");
}

void bfs(string init) {
   queue<string> q;
   q.push(init);
   level[init] = 0;

   string v;
   while (!q.empty()) {
      v = q.front();
      q.pop();

      for (string u: graph[v]) //para cada nó ainda não visitado
         if (!level.count(u)) {
            level[u] = level[v]+1;
            q.push(u);
         }
   }
}
//busca em profundidade
void dfs(string v, ofstream &out) {
   if (v != "root") {
      if (level[v] == 1)
         out << "# " << v << endl;

      else {
         for (int i = 0; i < level[v]-2; i++)
            out << "\t";
         
         if (graph[v].empty()) //nó folha
            out << "- " << v << endl;
         else
            out << endl << "- ## " << v << ":" << endl;
      }
   }
   for (string u: graph[v])
      dfs(u, out);
}

int main() {
   initJudgeURLs();
   readAllCppFilesTrackedOnGit();

   ofstream out("README.md");
   out << "[TOC]" << endl; //tabela de conteúdos

   bfs("root"); //get node levels
   dfs("root", out); //overwrite README.md

   out.close();
   system("git add README.md");
   return 0;
}