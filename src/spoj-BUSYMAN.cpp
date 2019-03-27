#include <iostream>
#include <vector>
#include <algorithm>
#define inicio second
#define final first
using namespace std;

int main()
{
    int t, n, inicio, fim;
    pair<int, int> tempoAux;
    cin >> t;
    while (t--)
    {
        cin >> n;

        //inicializa vetor tempo vazio
        vector<pair<int, int> > tempo;
        for (int i = 0; i < n; i++)
        {
            cin >> inicio >> fim;
            tempo.push_back(make_pair(fim, inicio));
        }
        //ordena por tempo final das atividades (considera o first, no caso final)
        sort(tempo.begin(), tempo.end());

        int numAtv = 1;
        tempoAux = tempo[0];
        for (int i = 1; i < n; i++)
            if (tempoAux.final <= tempo[i].inicio)
            {
                numAtv++;
                tempoAux = tempo[i];
            }
        cout << numAtv << endl;
    }
    return 0;
}