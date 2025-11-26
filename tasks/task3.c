#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pratosComidos;
} Filosofo;

int todosComeram(Filosofo *v){
    for (int i = 0; i < 5; i++){
        if ((v+i)->pratosComidos == 0) return 0;
    }
    return 1;
}

void simular(Filosofo *v, int rodadas){
    int garfos[5] = {0,0,0,0,0};

    for (int r = 0; r < rodadas; r++){
        for (int k = 0; k < 5; k++){
            int i = (r + k) % 5;
            int esq = i;
            int dir = (i + 1) % 5;

            if (garfos[esq] == 0 && garfos[dir] == 0){
                garfos[esq] = 1;
                garfos[dir] = 1;
                (v+i)->pratosComidos++;
                strcat((v+i)->nome, "COME");
            }
        }

        for (int i = 0; i < 5; i++)
            garfos[i] = 0;

        if (todosComeram(v)) break;
    }
}

int main(){
    Filosofo f[5] = {
        {"Aristoteles", 0},
        {"Platao", 0},
        {"Socrates", 0},
        {"Kant", 0},
        {"Nietzsche", 0}
    };

    int rodadas;

    printf("Rodadas: ");
    scanf("%d", &rodadas);

    simular(f, rodadas);

    int total = 0;

    printf("Nomes: ");
    for (int i = 0; i < 5; i++){
        printf("%s", f[i].nome);
        if (i < 4) printf(", ");
        total += f[i].pratosComidos;
    }

    printf(";\nTotal de pratos comidos: %d\n", total);

    return 0;
}