#include <iostream>
#include <string>
using namespace std;
#define MAX 300
//ed

string in2pos(string in)
{
    char pilha[MAX];
    int t = -1; //índice do topo da pilha

    string str;
    for (int i = 0; i < in.size(); i++)
    {
        if (isalnum(in[i]))
        {
            str += in[i];
        }
        else if (in[i] == '(')
        {
            pilha[++t] = in[i];
        }
        else if (in[i] == ')')
        {
            while (t >= 0 && pilha[t] != '(')
                str += pilha[t--];
            t--; //remove '('
        }
        else
        { 
            if (in[i] == '^')
                while (t >= 0 && pilha[t] != '(' && pilha[t] != '+' && pilha[t] != '-' && pilha[t] != '*' && pilha[t] != '/')
                    str += pilha[t--];

            else if (in[i] == '*' || in[i] == '/')
                while (t >= 0 && pilha[t] != '(' && pilha[t] != '+' && pilha[t] != '-')
                    str += pilha[t--];

            else if (in[i] == '+' || in[i] == '-')
                while (t >= 0 && pilha[t] != '(')
                    str += pilha[t--];

            pilha[++t] = in[i];
        }
    }
    while (t >= 0)
        str += pilha[t--];
    return str;
}

int main()
{
    int n;
    string in;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        cout << in2pos(in) << endl;
    }
    return 0;
}