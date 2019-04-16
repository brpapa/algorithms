#include <iostream>
using namespace std;
typedef struct llde {
   int info;
   struct llde *esq, *dir;
} *node;

void insere(node &arv, int info)
{
   if (arv == NULL)
   {
      node p = (node)malloc(sizeof(struct llde));
      p->info = info;
      p->esq = p->dir = NULL;
      arv = p;
   }
   else
   {
      if (info < arv->info)
         insere(arv->esq, info);
      if (info > arv->info)
         insere(arv->dir, info);
   }
}
void prefix(node arv)
{
   if (arv == NULL)
      return;
   printf(" %d", arv->info);
   prefix(arv->esq);
   prefix(arv->dir);
}
void infix(node arv)
{
   if (arv == NULL)
      return;
   infix(arv->esq);
   printf(" %d", arv->info);
   infix(arv->dir);
}
void posfix(node arv)
{
   if (arv == NULL)
      return;
   posfix(arv->esq);
   posfix(arv->dir);
   printf(" %d", arv->info);
}
int main() {
   int c, n, aux;
   scanf("%d", &c);
   for (int i = 1; i <= c; i++)
   {
      node arv = NULL;
      scanf("%d", &n);
      while (n--)
      {
         scanf("%d", &aux);
         insere(arv, aux);
      }
      printf("Case %d:", i);
      printf("\nPre.:");
      prefix(arv);
      printf("\nIn..:");
      infix(arv);
      printf("\nPost:");
      posfix(arv);
      printf("\n\n");
   }
   return 0;
}