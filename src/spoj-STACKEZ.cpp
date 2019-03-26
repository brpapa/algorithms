#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t, op;
    long long int n;
    stack<long long int> pilha;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%lli", &n);
            pilha.push(n);
        }
        else if (op == 2 && !pilha.empty())
        {
            pilha.pop();
        }
        else if (op == 3)
        {
            if (!pilha.empty())
                printf("%lli\n", pilha.top());
            else
                printf("Empty!\n");
        }
    }
    return 0;
}