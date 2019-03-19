#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int quant = 0;
    for (int k = 1; k <= sqrt(n); k++)
    {
        for (int i = k; i * k <= n; i++)
        {
            quant++;
        }
    }
    cout << quant << endl;
    return 0;
}