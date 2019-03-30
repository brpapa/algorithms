#include <iostream>
#include <string>
using namespace std;

bool strContemSub(string sub, string str)
{
    for (int i = 0; i <= (str.size()-sub.size()); i++)
        if (sub == str.substr(i, sub.size()))
            return true;
    return false;
}
int main()
{
    int t, n, anterior, aux;
    char str[100001];
    string sub;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> anterior;
        for (int i = 1; i < n; i++)
        {
            cin >> aux;

            if (aux == anterior)
                str[i-1] = 'E';
            else if (aux > anterior)
                str[i-1] = 'G';
            else if (aux < anterior)
                str[i-1] = 'L';
            anterior = aux;
        }
        str[n] = '\0';
        cin >> sub;
        printf("%s\n", strContemSub(sub, str)? "YES" : "NO");
    }
    return 0;
}