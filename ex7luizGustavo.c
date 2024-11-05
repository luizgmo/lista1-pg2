#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

void gerarMatriz(int matriz[8][8]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            matriz[i][j] = rand() % 2;
        }
    }
}

void imprimirMatriz(int matriz[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matriz1[N][N], matriz2[N][N];

    gerarMatriz(matriz1);
    gerarMatriz(matriz2);

    imprimirMatriz(matriz1);
    printf("\n");
    imprimirMatriz(matriz2);
}