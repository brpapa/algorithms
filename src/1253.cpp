#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, pos;
    string cifra;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cifra >> pos;
        for (int j = 0; j < cifra.size(); j++) {
            //A = 65, Z = 90
            cifra[j] -= pos;
            if (cifra[j] < 65)
                cifra[j] += 26;
        }
        cout << cifra << endl;
    }
    return 0;
}