#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const string INPUT_FILE = "./_scripts/files-tracked-on-git.txt";
const string OUTPUT_FILE = "./_scripts/problems.csv";

ofstream out(OUTPUT_FILE);

// substitui b por c em a
string replaceCh(string a, char b, char c) {
   string r;
   for (int i = 0; i < a.size(); i++) {
      if (a[i] == b)
         r.push_back(c);
      else
         r.push_back(a[i]);
   }
   return r;
}
vector<string> separateTopics(string line) {
   vector<string> topics;

   int b;
   line.erase(0, 3); // remove tab

   while ((b = line.find(">")) != string::npos) {
      topics.push_back(line.substr(0, b - 1));
      line.erase(0, b + 2);
   }
   topics.push_back(line);
   return topics;
}

void readFile(string ext, string folder, string file) {
   string line;
   ifstream in(folder + "/" + file + "." + ext);

   getline(in, line); // /*

   getline(in, line); // theme > topic1 > topic2
   vector<string> subjects = separateTopics(line);
   string theme = subjects[0];
   for (int i = 1; i < subjects.size(); i++)
      theme += " > " + subjects[i];
   
   getline(in, line);
   string difficulty = line.substr(15);
   
   getline(in, line);
   string date = line.substr(9);

   string problemDesc = "none", solutionDesc = "none";
   getline(in, line);
   if (line.find("problem") != string::npos) {
      problemDesc = line.substr(12);
      getline(in, line);
   }
   if (line.find("solution") != string::npos)
      solutionDesc = line.substr(13);

   string judge = folder;
   string problem = file;

   out << "\"" << judge << "\",\"" << problem << "\",\"" << problemDesc << "\",\"" << difficulty << "\",\"" << theme << "\",\"" << solutionDesc << "\",\"" << date << "\",\"" << ext << "\"" << endl;

   in.close();
}

void readAllFilesTrackedOnGit() {
   ifstream in(INPUT_FILE);

   string line;
   while (!in.eof()) {
      getline(in, line);
      
      string ext = "";
      if (line.find(".cpp") != string::npos) ext = "cpp";
      if (line.find(".py") != string::npos)  ext = "py";

      int b = line.find("/"), p = line.find(".");
      string folder = line.substr(0, b);
      string file = line.substr(b+1, p-b-1);

      if (ext == "" || (folder != "codeforces" && folder != "spoj" && folder != "uri" && folder != "uva" && folder != "codejam"))
         continue; // line não é exercicio

      readFile(
         ext,
         line.substr(0, b),      // folder
         line.substr(b+1, p-b-1) // file without ext
      );
   }
   in.close();
}

int main() {
   out << "judge,problem,name,difficulty,theme,solution,date,ext" << endl;
   readAllFilesTrackedOnGit();
   out.close();
   return 0;
}
