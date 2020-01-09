// executar na raiz do projeto
//! erro ao nomear problema com ','

#include "./header.h"
const string CACHE_PATH = "_scripts/files-tracked-on-git.lock";
const string WRITE_PATH = "problems.csv";


ofstream out(WRITE_PATH);

void readCppFile(string folder, string file) {
   string line;
   ifstream in(folder + "/" + file + ".cpp");

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

void readAllCppFilesTrackedOnGit() {
   ifstream in(CACHE_PATH);

   string line;
   while (!in.eof()) {
      getline(in, line);
      if (line.find(".cpp") == string::npos || line.find("_scripts") != string::npos)
         continue; //line não contém ".cpp"

      int b = line.find("/"), p = line.find(".");
      readCppFile(
          line.substr(0, b),            //folder
          line.substr(b + 1, p - b - 1) //file without .cpp
      );
   }
   in.close();
}

int main() {
   out << "judge,problem,name,difficulty,theme,topics,date" << endl;
   readAllCppFilesTrackedOnGit();

   out.close();
   return 0;
}
