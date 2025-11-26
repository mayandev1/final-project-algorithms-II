#include <stdio.h>

float raiz_quadrada(float numero) {
    float x = numero;       
    float anterior = 0.0;     
    float precisao = 0.0000001; 

    while (x - anterior > precisao || anterior - x > precisao) {
        anterior = x;
        x = (x + numero / x) / 2.0; 
    }

    return x;
}

int main() {
    float numero, resultado;

    while (1) {
        printf("Digite um numero real positivo (negativo para sair): ");
        scanf("%f", &numero);

        if (numero < 0) {
            printf("Programa encerrado!!!\n");
            break;
        }

        resultado = raiz_quadrada(numero);

        printf("Raiz quadrada = %.2f\n", resultado);
    }

    return 0;
}
