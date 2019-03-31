#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n, aux;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;

        queue<int> fila; //inicializa a formação inicial vazia
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &aux);
            fila.push(aux);
        }

        stack<int> pilha;
        for (int sEsp = 1; sEsp <= n; sEsp++)
        {
            // printf("%d: %d %d\n", sEsp, fila.empty()? 0: fila.front(), pilha.empty()? 0: pilha.top());
            if (!pilha.empty() && pilha.top() == sEsp)
            {
                    pilha.pop();
                    continue;
            }
            if (!fila.empty())
            {
                if (fila.front() != sEsp)
                {
                    pilha.push(fila.front());
                    fila.pop();
                    sEsp--; //como não é a saída esperada, não pode ser incrementada na próxima iteração
                }
                else fila.pop();
            }
        }
        printf("%s\n", (pilha.empty() && fila.empty())? "yes" : "no");
    }
}