#include <iostream>
using namespace std;

int main()
{
    int aux;
    while (true)
    {
        cin >> aux;
        if (aux == 42)
            return 0;
        cout << aux << endl;
    }
}