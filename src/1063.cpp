#include <iostream>
using namespace std;
#define MAX 26
//ed

int main()
{
    int n, t, e, s;
    bool ok;
    char entrada[MAX], saida[MAX], pilha[MAX];
    while (true)
    {
        cin >> n;
        if (n == 0) return 0;

        for (int i = 0; i < n; i++)
            cin >> entrada[i];
        for (int i = 0; i < n; i++)
            cin >> saida[i];

        //topo da pilha, indice da saida
        t = -1; s = 0; 
        for (int i = 0; i < n; i++)
        {
            cout << "I";
            pilha[++t] = entrada[i];
            
            while (t > -1 && pilha[t] == saida[s])
            {
                cout << "R";
                t--;
                s++;
            }
        }
        //se t == -1, a pilha está vazia
        printf("%s", (t == -1) ? "\n" : " Impossible\n");
    }
}