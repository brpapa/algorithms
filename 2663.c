#include <stdio.h>
#include <stdlib.h>

void leEntrada(int *n, int *k) {
    do {
        scanf("%d", n);
    } while (!(*n >= 1 && *n <= 1000));
    do {
        scanf("%d", k);
    } while(!(*k >= 1 && *k <= *n));
}
void ordenaVet(int *v, int n) {
    int p_maior, aux;
    for (int i = 0; i < n-1; i++) {
        p_maior = i;
        for (int j = i+1; j < n; j++)
            if (v[j] > v[p_maior])
                p_maior = j;
        //troca vet[p_maior] com vet[i]
        if (i != p_maior) {
            aux = v[p_maior];
            v[p_maior] = v[i];
            v[i] = aux;
        }
    }
}
int main() {
    int n, k, *pont;
    leEntrada(&n, &k);
    pont = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        do {
            scanf("%d", &pont[i]);
        } while (!(pont[i] >= 1 && pont[i] <= 1000));
    }
    ordenaVet(pont, n);

    int numComp = k; //numero minimo de competidores
    while (pont[numComp-1] == pont[numComp] && numComp < n)
        numComp++;
    printf("%d\n", numComp);
}