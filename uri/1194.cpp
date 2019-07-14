/*
   graph | binary search tree (BST)
   problem: pre, in and post
   author: @brnpapa
*/
#include <iostream>
using namespace std;

string pos(string pre, string in){
   if (pre.size() == 0)
      return "";

   int i;
   //encontra posição da raiz em in
   for (i = 0; i < in.size() && in[i] != pre[0]; i++);

   string raiz = pre.substr(0, 1);

   string preEsq = pre.substr(1, i);
   string preDir = pre.substr(i + 1, pre.size() - i - 1);

   string inEsq = in.substr(0, i);
   string inDir = in.substr(i + 1, in.size() - i - 1);

   // printf("%d %s -> pre: %s, %s\tin: %s, %s\n", i, raiz.c_str(), preEsq.c_str(), preDir.c_str(), inEsq.c_str(), inDir.c_str());
   return pos(preEsq, inEsq) + pos(preDir, inDir) + raiz;
}

int main() {
   int c, n;
   string pre, in;
   scanf("%d", &c);
   while (c--) {
      scanf("%d", &n);
      cin >> pre >> in;
      cout << pos(pre, in) << endl;
   }
   return 0;
}