#include <stdio.h>

int lerDna(char dna[9]){
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
        if (dna[i] == 'A'){
            contador++;
        }
    }
    return contador;
}

void contarDna(int contador){
    if (contador > 4){
        printf("Adenina aparece mais que 4 vezes nesse DNA!\n");
    } else{
        printf("Adenina não aparece mais que 4 vezes nesse DNA!\n");
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
    int contador;

    contador = lerDna(dna);

    system("clear");

    imprimirDna(dna);

    contarDna(contador);
}