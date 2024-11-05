#include <stdio.h>
#include <stdlib.h>

#define N 3

void inicializarMatriz(char matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 'O';
        }
    }
}

void exibirMatriz(char matriz[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void comerChocolate(char matriz[N][N], int linha, int coluna) {
    for (int i = linha; i < N; i++) {
        for (int j = coluna; j < N; j++) {
            matriz[i][j] = ' ';
        }
    }
}

int movimentoValido(char matriz[N][N], int linha, int coluna) {
    return linha >= 0 && linha < N && coluna >= 0 && coluna < N && matriz[linha][coluna] == 'O';
}

int verificarFimDoJogo(char matriz[N][N]) {
    return matriz[0][0] == ' ';
}

void jogar(char matriz[N][N]) {
    char jogadorAtual = 'A';
    int linha, coluna;

    while (!verificarFimDoJogo(matriz)) {
        exibirMatriz(matriz);
        printf("Jogador %c, escolha linha e coluna para comer (0 a %d): ", jogadorAtual, N - 1);
        scanf("%d %d", &linha, &coluna);

        if (movimentoValido(matriz, linha, coluna)) {
            comerChocolate(matriz, linha, coluna);
            if (verificarFimDoJogo(matriz)) {
                printf("Jogador %c ganhou!\n", jogadorAtual);
                break;
            }
            jogadorAtual = (jogadorAtual == 'A') ? 'B' : 'A';
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }
}

int main() {
    char matriz[N][N];

    inicializarMatriz(matriz);
    jogar(matriz);
    
}
