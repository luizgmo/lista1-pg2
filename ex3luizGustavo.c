#include <stdio.h>

#define N 5

void lerMatriz(int matriz[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("Posição %d x %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void somarLinha(int matriz[N][N], int vetSoma[N]){
    int i, j, soma = 0;

    for (i = 0; i < N; i++){
        soma = 0;
        for (j = 0; j < N; j++){
            soma += matriz[i][j];
            vetSoma[i] = soma;
        }
        printf("Soma da linha %d = %d\n", i + 1, soma);
    }
    printf("Vetor da soma das linhas: ");
    for (i = 0; i < N; i++) {
        printf("%d ", vetSoma[i]);
    }
    printf("\n");
    
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
    int vetSoma[N];

    lerMatriz(matriz);

    system("clear");

    imprimirMatriz(matriz);

    somarLinha(matriz, vetSoma);
}