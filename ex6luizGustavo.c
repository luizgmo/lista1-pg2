#include <stdio.h>

#define N 5

void lerVetorV(int vetorV[N]){
    int i;
    for (i = 0; i < N; i++){
        printf("Digite o número da posição %d do vetor V: ", i + 1);
        scanf("%d", &vetorV[i]);
    }
}

void lerVetorT(int vetorT[N]){
    int i;
    for (i = 0; i < N; i++){
        printf("Digite o número da posição %d do vetor T: ", i + 1);
        scanf("%d", &vetorT[i]);
    }
}

void imprimirVetor(int vetor[]){
    int i;
    for (i = 0; i < N; i++) {
        printf("%3d", vetor[i]);
    }
    printf("\n");
}

void calcularMatriz(int matrizA[N][N], int vetorT[N], int vetorV[N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            matrizA[i][j] = vetorT[i] * vetorV[j];
        }
    }
}

void imprimirMatriz(int matrizA[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%3d ", matrizA[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int vetorV[N], vetorT[N], matrizA[N][N];

    lerVetorV(vetorV);
    lerVetorT(vetorT);
    imprimirVetor(vetorV);
    imprimirVetor(vetorT);
    calcularMatriz(matrizA, vetorT, vetorV);
    imprimirMatriz(matrizA);
}