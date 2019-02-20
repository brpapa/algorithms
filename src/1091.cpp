#include <iostream>
using namespace std;

int main() {
    //entrada
    int k=1, n, m, x, y;
    cin >> k;
    do {
        //leste-oeste    sul-norte
        cin >> n >> m;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            if (x == n || y == m)
                printf("divisa\n");
            //leste
            else {

                if (x > n) {
                    if (y > m) {
                        printf("NE\n");
                    }
                    else {
                        printf("SE\n");
                    }
                }
                //oeste
                else {
                    if (y > m) {
                        printf("NO\n");
                    }
                    else {
                        printf("SO\n");
                    }
                }
            }
        }


        cin >> k;
    } while (k != 0);
    return 0;
}