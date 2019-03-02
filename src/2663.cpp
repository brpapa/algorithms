#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, aux;
    cin >> n >> k;
    vector<int> pont(n);
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        pont.push_back(aux);
    }
    //sort() is from algorithm library
    sort(pont.begin(), pont.end(), greater<int>()); 

    int minComp = k;
    while (pont[minComp - 1] == pont[minComp] && minComp < n)
        minComp++;
    cout << minComp << endl;
    return 0;
}