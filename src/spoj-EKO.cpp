#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m, aux;
    cin >> n >> m;
    priority_queue<int> heap;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        heap.push(aux);
    }

    int somaCortes = 0, quantPop = 0;
    int max = heap.top();

    while (true)
    {
        if (max == heap.top())
        {
            heap.pop();
            quantPop++;
        }
        max--;
        somaCortes += 1 * quantPop;

        if (somaCortes >= m)
        {
            cout << max << endl;
            break;
        }
    }

    return 0;
}