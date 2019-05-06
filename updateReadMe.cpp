// organiza problemas por theme(cont) e topic(what), 
// inspirado em: https://github.com/juanplopes/icpc/blob/master/README.md

// as 4 linhas iniciais de todo .cpp precisam estar padronizadas da seguinte forma:
/*
   theme | topic
   problem: name
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#define key first
#define value second
using namespace std;

typedef struct {
   string name, judge, arq, url;
} Tex;
typedef struct {
   map<string, vector<Tex> > what;
} Treg;

int main() {
   string aux, judge[4] = {
      "codeforces", 
      "spoj", 
      "uri", 
      "uva"
   }, url[4] = {
      "https://vjudge.net/problem/codeforces-", 
      "https://vjudge.net/problem/spoj-", 
      "https://www.urionlinejudge.com.br/judge/problems/view/", 
      "https://vjudge.net/problem/uva-"
   };


   vector<Tex> exerc;
   Tex ex; 
   //guarda todos os exercicios do diretório no vector exerc
   for (int i = 0; i < 4; i++) {
      system(("ls " + judge[i] + " > temp.bat").c_str());
      ex.judge = judge[i];

      ifstream arq("temp.bat", ios::in);
      while (!arq.fail()) {
         getline(arq, aux);
         if (aux == "")
            continue;
         ex.arq = aux.substr(0, aux.size()-4); //retira .cpp
         ex.url = url[i] + ex.arq;
   
         exerc.push_back(ex);
      }
      arq.close();
   }
   system("rm -f temp.bat");


   Tex p;
   map<string, Treg> cont;
   string keyCont, keyWhat, path;
   //separa as strings
   for (int k, i = 0; i < exerc.size(); i++) {
      path = exerc[i].judge + "/" + exerc[i].arq + ".cpp";

      ifstream arq(path, ios::in);
      getline(arq, aux);
      if (aux[0] != '/' || aux[1] != '*')
         continue;

      getline(arq, aux);
      k = aux.find('|'); //retorna posicão do separador
      keyCont = aux.substr(3, k-4);
      keyWhat = aux.substr(k+2);

      getline(arq, aux);
      exerc[i].name = aux.substr(12);

      cont[keyCont].what[keyWhat].push_back(exerc[i]);     
      arq.close();
   }


   ofstream arq("README.md");
   map<string, Treg>::iterator itC; //map cont
   map<string, vector<Tex> >::iterator itW; //map what
   //sobrescreve README.md
   for (itC = cont.begin(); itC != cont.end(); itC++) {
      arq << "\n# " << itC->key << endl;

      for (itW = itC->value.what.begin(); itW != itC->value.what.end(); itW++) {
         arq << "- " << itW->key << endl;
         vector<Tex> aux = itC->value.what[itW->key];

         //para cada exercício
         for (int i = 0; i < aux.size(); i++) {
            ex = aux[i];
            arq << "\t- [" << ex.judge << "/" << ex.arq << ": " << ex.name << "](" << ex.url << ")\n";
         }
      }
   }
   arq.close();
   system("git add README.md");
   return 0;
}