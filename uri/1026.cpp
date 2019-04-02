#include <iostream>
using namespace std;

int main()
{
    unsigned int a, b;
    while (scanf("%u %u", &a, &b) != EOF)
        printf("%u\n", a^b);
    return 0;
}   