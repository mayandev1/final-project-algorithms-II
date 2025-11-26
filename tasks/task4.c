#include <stdio.h>

int contarPares(int *tamanhos, char *lados) {
    int pares = 0;
    int usado[6] = {0}; 

    for (int i = 0; i < 6; i++) {

        if (usado[i] == 0) {

            for (int j = i + 1; j < 6; j++) {

                if (*(tamanhos + i) == *(tamanhos + j) &&
                    lados[i] != lados[j] &&
                    usado[j] == 0) {

                    pares++;
                    usado[i] = 1;
                    usado[j] = 1;
                    break; 
                }
            }
        } 
    }

    return pares;
}

int main() {
    int tamanhos[6];
    char lados[6];

    printf("Digite os tamanhos das 6 botas:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", tamanhos + i); 
    }

    printf("Digite os lados das 6 botas (E ou D):\n");
    for (int i = 0; i < 6; i++) {
        scanf(" %c", &lados[i]);
    }

    int totalPares = contarPares(tamanhos, lados);

    printf("\nTotal de pares encontrados: %d\n", totalPares);

    return 0;
}