#include <stdio.h>
#include <stdlib.h>

float calcularValorMedio(int *v, int n){
    int soma = 0;

    for (int i = 0; i < n; i++){
        soma += *(v + i);
    }
    
    return (float)soma/n;

}

void reorganizarVetor(int *v, int n, float media){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){

            int distancia1 = *(v + i) - media;
            
            if (distancia1 < 0){
                distancia1 *= -1;
            }
            
            int distancia2 = *(v + j) - media;
            
            if (distancia2 < 0){
                distancia2 *= -1;
            }

            if (distancia2 < distancia1 || (distancia1 == distancia2 && *(v + j) < *(v + i))){
                int temp = *(v + i);
                *(v + i) = *(v + j);
                *(v + j) = temp;
            }
        }
    }
}

int main(){
    int N;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    
    int vetor[N];
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }
    
    system("clear"); 
    
    int *p = vetor;
    
    float media = calcularValorMedio(p, N);
    reorganizarVetor(p, N, media);
    
    printf("Vetor Reorganizado: ");
    for (int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}