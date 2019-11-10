#include "./header.h"
ofstream out("./problems-table.csv");

void readCppFile(string folder, string file) {
   string line;
   vector<string> topics;
   ifstream in(folder+"/"+file+".cpp");

   getline(in, line); // /*

   getline(in, line); // theme | topic1 | topic2
   separateTopics(line, topics);

   getline(in, line);

   if (line.find("difficulty") != string::npos) {

      string difficulty = line.substr(15);

      getline(in, line);
      string name = line.substr(12);
      getline(in, line);
      string date = line.substr(9);

      string path = folder + "/" + file;

      out << name << "," << path << "," << difficulty << "," << date;
      for (int i = 0; i < topics.size(); i++)
         out << "," << topics[i];
      out << endl;
   }

   in.close();
}

void readAllCppFilesTrackedOnGit() {
   string line;
   system("git ls-files > _scripts/filesTrackedOnGit.txt");

   ifstream in ("_scripts/filesTrackedOnGit.txt");
   while (!in.eof()) {
      getline(in, line);
      if (line.find(".cpp") == string::npos || line.find("_scripts") != string::npos)
         continue; //line não contém ".cpp"

      int b = line.find("/"), p = line.find(".");
      readCppFile(
         line.substr(0, b), //folder
         line.substr(b+1, p-b-1) //file without .cpp
      );
   }
   in.close();
}

int main() {
   out << "name,problem,difficulty,date,theme,sub1,sub2,sub3" << endl; 
   readAllCppFilesTrackedOnGit();

   out.close();
   return 0;
}
