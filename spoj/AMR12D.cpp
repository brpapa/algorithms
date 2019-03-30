#include <iostream>
#include <string>
using namespace std;

bool ehPalindrome(string str)
{
    for (int i = 0; i < str.size()/2; i++)
        if (str[i] != str[str.size()-i-1])
            return false;
    return true;
}

int main()
{
    int t;
    string str;
    cin >> t >> ws;
    for (int i = 0; i < t; i++)
    {
        getline(cin, str);
        printf("%s\n", ehPalindrome(str)? "YES" : "NO");
    }
    return 0;
}