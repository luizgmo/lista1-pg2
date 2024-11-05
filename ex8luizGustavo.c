#include <stdio.h>

#define N 10

void imprimirMatriz(int matriz[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void escolherObstaculos(int matriz[N][N]){
    matriz[3][2] = -1;
    matriz[7][4] = -1;
    matriz[8][1] = -1;
    matriz[5][5] = -1;
    matriz[9][6] = -1;
    matriz[3][8] = -1;
    matriz[2][5] = -1;
    matriz[9][9] = 9;
    matriz[0][0] = 1;
}

void moverRobo(int matriz[N][N]){
    int x = 0, y = 0;
    int novoX, novoY;
    int jogoAtivo = 1;

    do {
        imprimirMatriz(matriz);
        printf("Digite as coordenadas x e y para o próximo passo (0 - 9): ");
        scanf("%d %d", &novoX, &novoY);

        if (novoX < 0 || novoX >= N || novoY < 0 || novoY >= N) {
            printf("Movimento fora dos limites!\n");
            continue;
        }

        if (!((novoX == x && (novoY == y + 1 || novoY == y - 1)) ||
              (novoY == y && (novoX == x + 1 || novoX == x - 1)) ||
              ((novoX == x + 1 || novoX == x - 1) &&
               (novoY == y + 1 || novoY == y - 1)))) {
            printf("Movimento inválido!\n");
            continue;
        }

        if (matriz[novoX][novoY] == -1) {
            printf("Você colidiu com um obstáculo!\n");
            jogoAtivo = 0;
        }

        if (matriz[novoX][novoY] == 9) {
            printf("Você venceu!\n");
            jogoAtivo = 0;
        }

        matriz[x][y] = 0;
        matriz[novoX][novoY] = 1;
        x = novoX;
        y = novoY;

    } while (jogoAtivo);
}

int main() {
    int matriz[N][N] = {0};

    escolherObstaculos(matriz);
    moverRobo(matriz);

}
