#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string exp;
    stack<char> p;
    int n, quant;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        quant = 0;
        cin >> exp;
        for (int i = 0; i < exp.size(); i++)
        {
            if (exp.at(i) == '<')
                p.push(exp.at(i));
            if (exp.at(i) == '>' && p.top() == '<')
                if (!p.empty())
                {
                    p.pop();
                    quant++;
                }
        }
        cout << quant << endl;

        while (!p.empty())
            p.pop();
    }
}