// executar na raiz do projeto
//! corrigir erro ao lidar com subtópicos idênticos de temas diferentes

#include "./header.h"
const string CACHE_PATH = "_scripts/files-tracked-on-git.lock";
const string WRITE_PATH = "problems.md";


ofstream out(WRITE_PATH);

// árvore de strings, sendo "root" o nó raiz
map<string, set<string, greater<string>>> graph;
// por default um set armazena em ordem crescente
// template: set<key, compare = less<key>, allocator = allocator<key>>

void readFile(string ext, string folder, string file) {
   string line, name;
   ifstream in(folder + "/" + file + ext);

   getline(in, line); // /*

   getline(in, line); // theme > topic1 > topic2
   vector<string> subjects = separateTopics(line);

   graph["root"].insert(subjects.front());
   for (int i = 0; i < subjects.size() - 1; i++)
      graph[subjects[i]].insert(subjects[i + 1]);

   string linkToMySolution = "[" + folder + "/" + file + "](https://github.com/brnpapa/icpc/blob/master/" + folder + "/" + file + ext+ ")";

   getline(in, line); // difficulty (modelo novo) ou name (modelo velho)
   if (line.find("difficulty") != string::npos) {
      string difficulty = line.substr(15);

      map<string, string> emoji;
      emoji["easy"] = "📗";
      emoji["medium"] = "📙";
      emoji["hard"] = "📕";

      getline(in, line);
      name = line.substr(12);

      // getline(in, line);
      // string date = line.substr(9);

      linkToMySolution = emoji[difficulty] + " " + linkToMySolution;
   } else {
      name = line.substr(12);
      string noDifficulty = "📓";
      linkToMySolution = noDifficulty + " " + linkToMySolution;
   }

   graph[subjects.back()].insert(linkToMySolution + ": " + name);
   in.close();
}

void readAllFilesTrackedOnGit() {
   ifstream in(CACHE_PATH);

   string line;
   while (!in.eof()) {
      getline(in, line);

      string ext = "";
      if (line.find(".cpp") != string::npos) ext = ".cpp";
      if (line.find(".py") != string::npos) ext = ".py";
      if (ext == "" || line.find("_scripts") != string::npos)
         continue; // line não é exercicio

      int b = line.find("/"), p = line.find(".");
      readFile(
         ext,
         line.substr(0, b),      // folder
         line.substr(b+1, p-b-1) // file without ext
      );
   }
   in.close();
}

void processNode(string node, int level) {
   if (node == "root")
      return;

   if (level == 1)
      out << "# " << node << endl;
   else {
      for (int i = 0; i < level - 2; i++)
         out << "\t";

      if (graph[node].empty()) //nó folha
         out << "- " << node << endl;
      else
         out << "- **" << node << "**" << endl;
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

      for (string u : graph[v])
         if (!level.count(u)) { //para cada nó não visitado
            level[u] = level[v] + 1;
            s.push(u);
         }
   }
}

void writeHeader() {
   stack<string> themes;
   for (string u : graph["root"])
      themes.push(u);

   while (!themes.empty()) {
      string link = replaceCh(themes.top(), ' ', '-');

      out << "- **[" + themes.top() + "](#" + link + ")**" << endl;
      themes.pop();
   }
   out << "\n\n";
}

int main() {
   readAllFilesTrackedOnGit();

   writeHeader();
   dfs("root");

   out.close();
   return 0;
}