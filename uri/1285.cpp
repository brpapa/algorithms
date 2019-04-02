#include <iostream>
#include <vector>
using namespace std;

bool repeteDig(int num)
{
    vector<bool> usados(10, false);
    while (num > 0)
    {
        int dig = num%10;
        if (usados[dig])
            return true;
            
        usados[dig] = true;
        num /= 10;
    }
    return false;
}
int main()
{
    int m, n;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int qte = 0;
        for (int i = n; i <= m; i++)
            if (!repeteDig(i))
                qte++;
        printf("%d\n", qte);
    }
    return 0;
}