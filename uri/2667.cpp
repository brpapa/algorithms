#include <iostream>
using namespace std;

int main()
{
    int a[4];
    cin >> a[1] >> a[2] >> a[3];
    int maq, min, m;

    for (int maq = 1; maq <= 3; maq++)
    {
        min = 0;
        for (int i = 1; i <= 3; i++)
            min += a[i] * abs(maq - i) * 2;

        if (maq == 1 || min < m)
            m = min;
    }
    cout << m << endl;
    return 0;
}