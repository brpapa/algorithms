#include <stdio.h>
#include <stdlib.h>

void readInput(int *n, int *k) {
    do {
        scanf("%d", n);
    } while (!(*n >= 1 && *n <= 1000));
    do {
        scanf("%d", k);
    } while(!(*k >= 1 && *k <= *n));
}
void sortArray(int *v, int n) {
    int p_bigger, aux;
    for (int i = 0; i < n-1; i++) {
        p_bigger = i;
        for (int j = i+1; j < n; j++)
            if (v[j] > v[p_bigger])
                p_bigger = j;
        //swap vet[p_bigger] with vet[i]
        if (i != p_bigger) {
            aux = v[p_bigger];
            v[p_bigger] = v[i];
            v[i] = aux;
        }
    }
}
int main() {
    int n, k, *scores;
    readInput(&n, &k);
    scores = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        do {
            scanf("%d", &scores[i]);
        } while (!(scores[i] >= 1 && scores[i] <= 1000));
    }
    sortArray(scores, n);

    int numComp = k; //minimum number of competitors
    while (scores[numComp-1] == scores[numComp] && numComp < n)
        numComp++;
    printf("%d\n", numComp);
}