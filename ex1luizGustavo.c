#include <stdio.h>

#define N 50
#define POSITIVOS N
#define NEGATIVOS N

void lerVetor(int vetor[N]){
    int i;
    for (i = 0; i < N; i++){
        printf("Digite o número da posição %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int lerVetorA(int vetor[N], int vetorA[POSITIVOS]){
    int i, tamanho = 0;
    for (i = 0; i < N; i++){
        if (vetor[i] > 0){
            vetorA[tamanho] = vetor[i];
            tamanho++;
        }
    }
    return tamanho;
}

int lerVetorB(int vetor[N], int vetorB[NEGATIVOS]){
    int i, tamanho = 0;
    for (i = 0; i < N; i++){
        if (vetor[i] < 0){
            vetorB[tamanho] = vetor[i];
            tamanho++;
        }
    }
    return tamanho;
}

int contarNulos(int vetor[N]){
    int i, contador = 0;
    for(i = 0; i < N; i++){
        if (vetor[i] == 0){
            contador++;
        }
    }
    return contador;
}

void imprimirVetor(int vetor[], int tamanho){
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%3d", vetor[i]);
    }
    printf("\n");
}

int main(){
    int vetor[N], vetorA[POSITIVOS], vetorB[NEGATIVOS];
    int tamA, tamB;

    lerVetor(vetor);

    printf("Vetor original:\n");
    imprimirVetor(vetor, N);

    tamA = lerVetorA(vetor, vetorA);

    printf("Vetor com valores positivos:");
    imprimirVetor(vetorA, tamA);

    tamB = lerVetorB(vetor, vetorB);

    printf("Vetor com valores negativos:");
    imprimirVetor(vetorB, tamB);

    printf("Quantidade de números nulos: %d\n", contarNulos(vetor));

    return 0;
}
