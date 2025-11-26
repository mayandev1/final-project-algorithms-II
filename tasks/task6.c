#include <stdio.h>
#include <stdlib.h>

void collatz(int x, FILE *arq) {
    int n = x;

    printf("%d: %d", x, n);
    fprintf(arq, "%d: %d", x, n);

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        printf(" -> %d", n);
        fprintf(arq, " -> %d", n);
    }

    printf("\n");
    fprintf(arq, "\n");
}

int main() {
    int n;
    FILE *arq;

    printf("Digite um valor: ");
    scanf("%d", &n);

    arq = fopen("collatz.txt", "w");
    if (arq == NULL) {
        return 1;
    }

    for (int i = 1; i < n; i++) {
        collatz(i, arq);
    }

    fclose(arq);
    return 0;
}
