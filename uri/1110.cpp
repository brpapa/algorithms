#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, descartes[51];
    while (true)
    {
        cin >> n;
        if (n == 0) 
            return 0;
        
        queue<int> fila; //cria fila
        for (int i = 1; i <= n; i++) 
            fila.push(i);

        //enquanto tem 2 cartas ou mais na fila (n-1 descartes)
        for (int i = 0; i < n-1; i++)
        {
            //descarta o topo
            descartes[i] = fila.front();
            fila.pop();

            //move o novo topo para a base
            fila.push(fila.front());
            fila.pop();
        }

        cout << "Discarded cards:";
        for (int i = 0; i <= n-3; i++)
            cout << " " << descartes[i] << ",";
        if (n > 1)
            cout << " " << descartes[n-2];
        cout << endl;

        cout << "Remaining card: " << fila.front() << endl;
    }
}