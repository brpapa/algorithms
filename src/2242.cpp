#include <iostream>
#include <string>
using namespace std;

bool ehVogal(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
bool ehEngracada(string str)
{
    int j = 0; char aux[50];
    for (int i = 0; i < str.size(); i++)
        if (ehVogal(str[i]))
            aux[j++] = str[i];

    j = 0;
    for (int i = str.size()-1; i >= 0; i--)
        if (ehVogal(str[i]))
            if (str[i] != aux[j++])
                return false;

    return true;
}

int main()
{
    string risada;
    cin >> risada;
    printf("%s\n", ehEngracada(risada)? "S" : "N");
    return 0;
}