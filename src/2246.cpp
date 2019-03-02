#include <iostream>
using namespace std;

int m[200][200], nLin, nCol;

int conta(int l, int c)
{
    if (l < 0 || c < 0 || l >= nLin || c >= nCol)
        return 0;

    int soma = 1;
    int cor = m[l][c];
    //ladrilho atual recebe -1 p indicar q já foi visitado!!!
    m[l][c] = -1;

    if (cor == m[l+1][c])
        soma += conta(l+1, c);
    if (cor == m[l-1][c])
        soma += conta(l-1, c);
    if (cor == m[l][c+1])
        soma += conta(l, c+1);
    if (cor == m[l][c-1])
        soma += conta(l, c-1);
    return soma;
}
int main() {
    cin >> nLin >> nCol;
    for (int l = 0; l < nLin; l++)
        for (int c = 0; c < nCol; c++)
            cin >> m[l][c];

    int minArea = nLin*nCol;
    for (int l = 0; l < nLin; l++)
        for (int c = 0; c < nCol; c++)
            if (m[l][c] >= 0) {
                int area = conta(l, c);
                minArea = (area < minArea)?area:minArea;
            }
    
    cout << minArea << endl;
    return 0;
}