// script para gerar automaticamente README.md

// nunca definir subtópicos idênticos de temas diferentes!
// header padrão de todo .cpp:
/*
   theme | subtopic1 | subtopic2
   problem: name
   author: @brnpapa
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
using namespace std;

//árvore de strings, sendo "root" o nó raiz
map<string, set<string, greater<string> > > graph;
//por default um set armazena em ordem crescente
//template: set<key, compare = less<key>, allocator = allocator<key>>

map<string, string> url;
ofstream out("README.md"); //overwrite README.md

string insertBefore(string a, char b, char c) {
   //insere c antes de b em a

   string r;
   for (int i = 0; i < a.size(); i++) {
      if (a[i] == b)
         r.push_back(c);

      r.push_back(a[i]);
   }
   return r;
}
void initJudgeURLs() {
   url["codeforces"] = "https://vjudge.net/problem/codeforces-";
   url["spoj"] = "https://spoj.com/problems/";
   url["uri"] = "https://www.urionlinejudge.com.br/judge/problems/view/";
   url["uva"] = "https://vjudge.net/problem/uva-";
   url["leetcode"] = "https://leetcode.com/problems/";
   url["hacker-rank"] = "https://www.hackerrank.com/challenges/";
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

   graph[topics.back()].insert(linkToMySolution + ": " + linkToProblemURL);
   in.close();
}
void readAllCppFilesTrackedOnGit() {
   string line;
   system("git ls-files > tmp.bat"); 

   ifstream in("tmp.bat");
   while (!in.eof()) {
      getline(in, line);
      if (line.find(".cpp") == string::npos || line == "auto.cpp")
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

void processNode(string node, int level) {
   if (node == "root")
      return;

   if (level == 1)
      out << "## " << node << endl;
   else {
      for (int i = 0; i < level-2; i++)
         out << "\t";

      if (graph[node].empty()) //nó folha
         out << "- " << node << endl;
      else out << "- **" << node << "**" << endl;
   }
}
void dfs(string init) {
   map<string, int> level;

   stack<string> s;
   s.push(init);
   level[init] = 0;

   string v;
   while (!s.empty()) {
      v = s.top();
      s.pop();
      processNode(v, level[v]);
      
      for (string u: graph[v]) 
         if (!level.count(u)) { //para cada nó não visitado
            level[u] = level[v]+1;
            s.push(u);
         }
   }
}

void writeHeader() {
   out << "# Solutions by theme" << endl;

   stack<string> themes;
   for (string u : graph["root"])
      themes.push(u);

   while (!themes.empty()) {
      string link = insertBefore(themes.top(), ' ', '\\');

      out << "- [" + themes.top() + "](#" + link + ")\t" << endl;
      themes.pop();
   }
}

int main() {
   initJudgeURLs();
   readAllCppFilesTrackedOnGit();

   writeHeader();
   dfs("root");

   out.close();
   system("git add README.md");
   return 0;
}