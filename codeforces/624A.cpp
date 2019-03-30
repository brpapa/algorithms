#include <iostream>
using namespace std;

int main()
{
    int d, L, v1, v2;
    cin >> d >> L >> v1 >> v2;
    double t = (double)(L - d) / (v1 + v2);
    printf("%0.16f\n", t);
    return 0;
}