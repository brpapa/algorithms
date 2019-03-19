#include <iostream>
using namespace std;
//ed

int main()
{
    int n, descartes[51], fila[51];
    while (true)
    {
        cin >> n;
        if (n == 0) 
            return 0;
        
        int t = -1; //topo da fila
        //cria fila
        for (int i = n; i >= 1; i--) 
            fila[++t] = i;

        //enquanto tem 2 cartas ou mais na fila
        for (int i = 0; t >= 1; i++)
        {
            //descarta o topo
            descartes[i] = fila[t--];

            //move o novo topo para a base
            int aux = fila[t];
            for (int i = t-1; i >= 0; i--)
                fila[i+1] = fila[i];
            fila[0] = aux;
        }

        cout << "Discarded cards:";
        for (int i = 0; i <= n-3; i++)
            cout << " " << descartes[i] << ",";
        if (n > 1)
            cout << " " << descartes[n-2];
        cout << endl;

        cout << "Remaining card: " << fila[0] << endl;
    }
}