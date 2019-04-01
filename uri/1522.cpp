#include <iostream>
using namespace std;

int pilhaA[100], pilhaB[100], pilhaC[100];
bool toposVrf[101][101][101], ok;

void testaTopos(int topoA, int topoB, int topoC)
{
    //verifica se a combinação atual de topos já foi testada, com +1 pois pode ser -1
    if (!toposVrf[topoA + 1][topoB + 1][topoC + 1])
        toposVrf[topoA + 1][topoB + 1][topoC + 1] = true;
    else
        return;

    if ((topoA == -1) && (topoB == -1) && (topoC == -1))
        ok = true;

    if ((topoA > -1) && (topoB > -1) && (topoC > -1) && !ok)
        if ((pilhaA[topoA] + pilhaB[topoB] + pilhaC[topoC]) % 3 == 0)
        {
            testaTopos(--topoA, --topoB, --topoC);
            topoA++; topoB++; topoC++; //backtracking
        }
    if ((topoA > -1) && (topoB > -1) && !ok)
        if ((pilhaA[topoA] + pilhaB[topoB]) % 3 == 0)
        {
            testaTopos(--topoA, --topoB, topoC);
            topoA++; topoB++;
        }
    if ((topoA > -1) && (topoC > -1) && !ok)
        if ((pilhaA[topoA] + pilhaC[topoC]) % 3 == 0)
        {
            testaTopos(--topoA, topoB, --topoC);
            topoA++; topoC++;
        }
    if ((topoB > -1) && (topoC > -1) && !ok)
        if ((pilhaB[topoB] + pilhaC[topoC]) % 3 == 0)
        {
            testaTopos(topoA, --topoB, --topoC);
            topoB++; topoC++;
        }
    if ((topoA > -1) && !ok)
        if (pilhaA[topoA] % 3 == 0)
        {
            testaTopos(--topoA, topoB, topoC);
            topoA++;
        }
    if ((topoB > -1) && !ok)
        if (pilhaB[topoB] % 3 == 0)
        {
            testaTopos(topoA, --topoB, topoC);
            topoB++;
        }
    if ((topoC > -1) && !ok)
        if (pilhaC[topoC] % 3 == 0)
        {
            testaTopos(topoA, topoB, --topoC);
            topoC++;
        }
}
int main()
{
    int n;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        for (int i = n - 1; i >= 0; i--)
            scanf("%d %d %d", &pilhaA[i], &pilhaB[i], &pilhaC[i]);

        int topoA = n - 1, topoB = n - 1, topoC = n - 1;
        ok = false;
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101; j++)
                for (int k = 0; k < 101; k++)
                    toposVrf[i][j][k] = false;
        testaTopos(topoA, topoB, topoC); //passagem por valor por causa da recursividade
        printf("%d\n", ok ? 1 : 0);
    }
    return 0;
}