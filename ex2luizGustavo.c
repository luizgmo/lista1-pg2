#include <stdio.h>

#define N 10

void lerMatriz(int matriz[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("Posição %d x %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int calcularTraco(int matriz[N][N]){
    int i, j, soma = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (i == j){
                soma += matriz[i][j];
            }
        }
    }
    return soma;
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
    int matriz[N][N];

    lerMatriz(matriz);

    system("clear");

    imprimirMatriz(matriz);

    printf("Soma da diagonal principal da matriz = %d\n", calcularTraco(matriz));
}