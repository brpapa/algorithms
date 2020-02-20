// executar na raiz do projeto
//! corrigir erro ao lidar com subtópicos idênticos de temas diferentes

#include "./header.h"
const string CACHE_PATH = "_scripts/files-tracked-on-git.lock";
const string WRITE_PATH = "problems.csv";


ofstream out(WRITE_PATH);

void readFile(string ext, string folder, string file) {
   string line;
   ifstream in(folder + "/" + file + ext);

   getline(in, line); // /*

   getline(in, line); // theme > topic1 > topic2
   vector<string> subjects = separateTopics(line);
   string theme = subjects[0], topics = "";
   for (int i = 1; i < subjects.size(); i++)
      topics += " > " + subjects[i];

   getline(in, line);
   if (line.find("difficulty") != string::npos) {

      string difficulty = line.substr(15);

      getline(in, line);
      string name = line.substr(12);
      getline(in, line);
      string date = line.substr(9);

      string judge = folder;
      string problem = file;

      out << "\"" << judge << "\",\"" << problem << "\",\"" << name << "\",\"" << difficulty << "\",\"" << theme << "\",\"" << topics << "\",\"" << date << "\"" << endl;
   }

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

int main() {
   out << "judge,problem,name,difficulty,theme,topics,date" << endl;
   readAllFilesTrackedOnGit();

   out.close();
   return 0;
}
