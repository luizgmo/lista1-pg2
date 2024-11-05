#include <stdio.h>

char escolherBase(){
    char base;
    while (base != 'A' && base != 'C' && base != 'G' && base != 'T'){
        printf("Escolha a base para verificar quantas vezes se repete (A/C/G/T): \n");
        scanf(" %c", &base);
    }
    return base;
}

int escolherVezes(){
    int vezes = -1;
    while (vezes < 0){
        printf("Escolha quantas repetições deseja verificar: \n");
        scanf("%i", &vezes);
    }
    return vezes;
}

int lerDna(char dna[9], char base){
    int i;
    int contador = 0;

    printf("Adenina (A), Citosina (C), Guanina (G) e Timina (T)\n");
    for (i = 0; i < 9; i++){
        printf("Digite a base %d: ", i + 1);
        scanf(" %c", &dna[i]);
        if (dna[i] != 'A' && dna[i] != 'C' && dna[i] != 'G' && dna[i] != 'T') {
            printf("Base inválida. Por favor, digite A, C, G ou T.\n");
            i--;
        }
        if (dna[i] == base){
            contador++;
        }
    }
    return contador;
}

void contarDna(int contador, int vezes){
    if (contador > vezes){
        printf("A base escolhida aparece mais que %i vezes nesse DNA!\n", vezes);
    } else{
        printf("A base escolhida não aparece mais que %i vezes nesse DNA!\n", vezes);
    }
}

void imprimirDna(char dna[9]){
    int i;
    for (i = 0; i < 9; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");
}

int main(){
    char dna[9];
    int contador, vezes;
    char base;

    base = escolherBase();
    vezes = escolherVezes();

    contador = lerDna(dna, base);

    system("clear");

    imprimirDna(dna);

    contarDna(contador, vezes);
}