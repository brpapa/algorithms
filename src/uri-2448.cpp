#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//retorna o indice do elem x no vetor
int buscaBin(int x, vector<unsigned int> v)
{
    int esq = 0, dir = v.size() - 1, m;
    while (dir - esq >= 0)
    {
        m = (esq + dir) / 2;
        if (x == v[m])
            return m;
        else if (x > v[m])
            esq = m + 1;
        else if (x < v[m])
            dir = m - 1;
    }
    //nunca ira acontecer, pois x sempre estara em v
    return -1;
}
int main()
{
    int N, M, aux;
    cin >> N >> M;
    vector<unsigned int> casas;
    for (int i = 0; i < N; i++)
    {
        cin >> aux;
        casas.push_back(aux);
    }
    queue<unsigned int> enc;
    for (int i = 0; i < M; i++)
    {
        cin >> aux;
        enc.push(aux);
    }

    int tempo = 0, c = 0, novo_c;
    while (!enc.empty())
    {
        novo_c = buscaBin(enc.front(), casas);
        enc.pop();
        tempo += abs(novo_c - c);
        c = novo_c;
    }
    cout << tempo << endl;
    return 0;
}