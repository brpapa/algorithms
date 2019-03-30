#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string exp;
    stack<char> p;
    while (cin >> exp)
    {
        bool ok = true;
        for (int i = 0; i < exp.size(); i++)
        {
            if (exp.at(i) == '(') {
                p.push(exp.at(i));
            }
            else if (exp.at(i) == ')')
            {
                if (!p.empty() && p.top() == '(')
                    p.pop();
                else
                    ok = false;
            }
        }
        printf("%s\n", (p.empty() && ok)?"correct":"incorrect");
        while (!p.empty())
            p.pop();
    }
}