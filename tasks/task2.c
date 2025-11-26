#include <stdio.h>
#include <string.h>
typedef struct {
    char palavras[100][30];
    int qtd;
} Frase;

void separarPalavras(char *frase, Frase *f){
    int i = 0, j = 0, k = 0;
    char temp[30];

    while (*(frase + i) != '\0' && *(frase + i) != '\n'){
        if (*(frase + i) != ' '){
            temp[j++] = *(frase + i);
        } else {
            if (j > 0){
                temp[j] = '\0';
                strcpy(f->palavras[k++], temp);
                j = 0;
            }
        }
        i++;
    }

    if (j > 0){
        temp[j] = '\0';
        strcpy(f->palavras[k++], temp);
    }

    f->qtd = k;
}

int existe(char palavras[][30], int qtd, char *p){
    for (int i = 0; i < qtd; i++){
        if (strcmp(*(palavras + i), p) == 0) return 1;
    }
    return 0;
}

int intersecao(Frase *a, Frase *b, char comuns[][30]){
    int k = 0;
    for (int i = 0; i < a->qtd; i++){
        if (existe(b->palavras, b->qtd, a->palavras[i])){
            if (!existe(comuns, k, a->palavras[i])){
                strcpy(comuns[k++], a->palavras[i]);
            }
        }
    }
    return k;
}

int uniao(Frase *a, Frase *b){
    char temp[200][30];
    int k = 0;

    for (int i = 0; i < a->qtd; i++){
        if (!existe(temp, k, a->palavras[i])){
            strcpy(temp[k++], a->palavras[i]);
        }
    }

    for (int i = 0; i < b->qtd; i++){
        if (!existe(temp, k, b->palavras[i])){
            strcpy(temp[k++], b->palavras[i]);
        }
    }

    return k;
}

float jaccard(int inter, int uniao){
    return (float)inter / uniao;
}

int main(){
    char frase1[200], frase2[200];
    Frase f1, f2;
    char comuns[100][30];

    printf("Frase 1: ");
    fgets(frase1, 200, stdin);

    printf("Frase 2: ");
    fgets(frase2, 200, stdin);

    separarPalavras(frase1, &f1);
    separarPalavras(frase2, &f2);

    int inter = intersecao(&f1, &f2, comuns);
    int uni = uniao(&f1, &f2);

    printf("Palavras em comum: ");
    for (int i = 0; i < inter; i++){
        printf("%s ", comuns[i]);
    }
    printf("\n");

    printf("Indice de Jaccard = %.2f\n", jaccard(inter, uni));

    return 0;
}