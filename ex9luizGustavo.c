#include <stdio.h>

void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int movimentoValido(char tabuleiro[3][3], int linha, int coluna) {
    return linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == ' ';
}

char verificarVencedor(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return tabuleiro[0][i];
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return tabuleiro[0][2];

    return ' ';
}

void escolherMovimento(char tabuleiro[3][3], char *vencedor){
    int linha, coluna, jogadas = 0;
    char jogador = 'A';

    while (jogadas < 9 && *vencedor == ' ') {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %c, escolha linha e coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (movimentoValido(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = (jogador == 'A') ? 'X' : 'O';
            jogadas++;
            *vencedor = verificarVencedor(tabuleiro);
            jogador = (jogador == 'A') ? 'B' : 'A';
        } else {
            printf("Movimento inválido! Tente novamente.\n");
        }
    }
}

void exibirVencedor(char vencedor) {
    if (vencedor != ' ') {
        printf("Jogador %c ganhou!\n", (vencedor == 'X') ? 'A' : 'B');
    } else {
        printf("Empate!\n");
    }
}

int main() {
    char tabuleiro[3][3];
    char vencedor = ' ';

    inicializarTabuleiro(tabuleiro);
    escolherMovimento(tabuleiro, &vencedor);
    exibirTabuleiro(tabuleiro);
    exibirVencedor(vencedor);

}
