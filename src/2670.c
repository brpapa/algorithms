#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[4];
    scanf("%d %d %d", &a[1], &a[2], &a[3]);
    int machine, minutes, min;

    for (int machine = 1; machine <= 3; machine++) {
        minutes = 0;
        for (int i = 1; i <= 3; i++)
            minutes += a[i]*abs(machine-i)*2;

        if (machine == 1)
            min = minutes;
        else if (minutes < min)
            min = minutes;
    }
    printf("%d\n", min);
    return 0;
}