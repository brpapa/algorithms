/*
   graphs > binary search tree (BST)
   difficulty: none
   problem: bst operations I
   date: none
   author: @brnpapa
*/
#include <iostream>
using namespace std;
typedef struct llde {
   char info;
   struct llde *esq, *dir;
} *Tnode;

int qteTotal, qte;

void insere(Tnode &arv, char info) {
   if (arv == NULL) {
      Tnode p = (Tnode)malloc(sizeof(struct llde));
      p->info = info;
      p->esq = p->dir = NULL;
      arv = p;
      qteTotal++;
   }
   else {
      if (info < arv->info)
         insere(arv->esq, info);
      if (info > arv->info)
         insere(arv->dir, info);
   }
}
void prefix(Tnode arv) {
   if (arv == NULL)
      return;
   printf("%c%c", arv->info, ((qte++) == qteTotal - 1) ? '\n' : ' ');
   prefix(arv->esq);
   prefix(arv->dir);
}
void infix(Tnode arv) {
   if (arv == NULL)
      return;
   infix(arv->esq);
   printf("%c%c", arv->info, ((qte++) == qteTotal - 1) ? '\n' : ' ');
   infix(arv->dir);
}
void posfix(Tnode arv) {
   if (arv == NULL)
      return;
   posfix(arv->esq);
   posfix(arv->dir);
   printf("%c%c", arv->info, ((qte++) == qteTotal - 1) ? '\n' : ' ');
}
bool bst(Tnode arv, char info) {
   if (arv != NULL) {
      if (info == arv->info)
         return true;
      if (info < arv->info)
         return bst(arv->esq, info);
      if (info > arv->info)
         return bst(arv->dir, info);
   }
   return false;
}

int main() {
   string str;
   Tnode arv = NULL;
   qteTotal = 0;
   while (getline(cin, str)) {
      if (str.size() == 3) {
         if (str[0] == 'I')
            insere(arv, str[2]);
         if (str[0] == 'P')
            printf("%c%sexiste\n", str[2], bst(arv, str[2]) ? " " : " nao ");
      }
      else {
         if (str == "INFIXA") {
            qte = 0;
            infix(arv);
         }
         if (str == "PREFIXA") {
            qte = 0;
            prefix(arv);
         }
         if (str == "POSFIXA") {
            qte = 0;
            posfix(arv);
         }
      }
   }
   return 0;
}