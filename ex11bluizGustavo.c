#include <stdio.h>
#include <time.h>

#define QNTD_CABECAS 48000

struct nasc{
    int mes;
    int ano;
};

struct registro{
    int codigo;
    double leite;
    double alim;
    struct nasc nasc;
    char abate;
};

void lerDados(struct registro registro[]){
    int i;

    for (i = 0; i < QNTD_CABECAS; i++) {

        do{
            printf("Digite o código da cabeça de gado: ");
            scanf("%d", &registro[i].codigo);
            if (registro[i].codigo < 0){
                printf("Código inválido!\n");
            }
        } while (registro[i].codigo < 0);

        do{
            printf("Digite a quantidade de leite produzido por semana (em L): ");
            scanf("%lf", &registro[i].leite);
            if (registro[i].leite < 0){
                printf("Quantidade inválida!\n");
            }
        } while(registro[i].leite < 0);

        do{
            printf("Digite a quantidade de alimento consumido por semana (em kg): ");
            scanf("%lf", &registro[i].alim);
            if (registro[i].alim < 0){
                printf("Quantidade inválida!\n");
            }
        } while(registro[i].alim < 0);

        do{
            printf("Digite o mês de nascimento (1 - 12): ");
            scanf("%d", &registro[i].nasc.mes);
            if (registro[i].nasc.mes < 1 || registro[i].nasc.mes > 12){
                printf("Mês inválido!\n");
            }
        } while (registro[i].nasc.mes < 1 || registro[i].nasc.mes > 12);

        printf("Digite o ano de nascimento: ");
        scanf("%d", &registro[i].nasc.ano);
    }
}

void preencherAbate(struct registro registro[]){
    int i, idade;
    time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);
    int anoAtual = dataAtual.tm_year + 1900;
    int mesAtual = dataAtual.tm_mon + 1;

    for (i = 0; i < QNTD_CABECAS; i++){
        idade = anoAtual - registro[i].nasc.ano;

        if (mesAtual < registro[i].nasc.mes){
            idade--;
        }

        if (idade > 5 || registro[i].leite < 40 || (registro[i].leite >= 50 && registro[i].leite <= 70 && registro[i].alim > 50)){
            registro[i].abate = 'S';
        } else{
            registro[i].abate = 'N';
        }
    }
}

void exibirCabecas(struct registro registro[]){
    int i;

    for (i = 0; i < QNTD_CABECAS; i++) {
        printf("\nDados da cabeça de gado %d:\n", i + 1);
        printf("Código: %d\n", registro[i].codigo);
        printf("Leite produzido por semana: %.2lf L\n", registro[i].leite);
        printf("Alimento consumido por semana: %.2lf kg\n", registro[i].alim);
        printf("Mês de nascimento: %d\n", registro[i].nasc.mes);
        printf("Ano de nascimento: %d\n", registro[i].nasc.ano);
        printf("Abate: %c\n", registro[i].abate);
    }
}

void mostrarLeite(struct registro registro[]){
    int i;
    double totalLeite = 0;

    for (i = 0; i < QNTD_CABECAS; i++){
        totalLeite += registro[i].leite;
    }

    printf("Total de leite produzido na semana: %.2lf L\n", totalLeite);
}

void mostrarAlim(struct registro registro[]){
    int i;
    double totalAlim = 0;

    for (i = 0; i < QNTD_CABECAS; i++){
        totalAlim += registro[i].alim;
    }

    printf("Total de alimento consumido na semana: %.2lf kg\n", totalAlim);
}

void mostrarLeiteAbate(struct registro registro[]){
    int i;
    double totalLeite = 0;

    for (i = 0; i < QNTD_CABECAS; i++){
        if (registro[i].abate != 'S'){
            totalLeite += registro[i].leite;
        }
    }

    printf("Total de leite que será produzido na semana após o abate: %.2lf L\n", totalLeite);
}

void mostrarAlimAbate(struct registro registro[]){
    int i;
    double totalAlim = 0;

    for (i = 0; i < QNTD_CABECAS; i++){
        if (registro[i].abate != 'S'){
            totalAlim += registro[i].alim;
        }
    }

    printf("Total de alimento que será consumido na semana após o abate: %.2lf kg\n", totalAlim);
}

void cabecasAbate(struct registro registro[]){
    int i, contador = 0;

    for (i = 0; i < QNTD_CABECAS; i++){
        if (registro[i].abate == 'S'){
            contador++;
        }
    }    

    printf("Total de cabeças que irão para o abate: %d\n", contador);
}

void menu(struct registro registro[]){
    int opcao;

    registro[0].codigo = -1;

    do{
        printf("\n1 - Ler dados\n");
        printf("2 - Preencher abate\n");
        printf("3 - Quantidade total de leite na semana\n");
        printf("4 - Quantidade total de alimento na semana\n");
        printf("5 - Quantidade total de leite na semana após o abate\n");
        printf("6 - Quantidade total de alimento na semana após o abate\n");
        printf("7 - Quantidade de cabeças que irão para o abate\n");
        printf("8 - Sair\n");

        printf("Digite uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            lerDados(registro);
            break;
        case 2:
            if (registro[0].codigo != -1){
                preencherAbate(registro);
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            
        case 3:
            if (registro[0].codigo != -1){
                mostrarLeite(registro);
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            break;
        case 4:
            if (registro[0].codigo != -1){
                mostrarAlim(registro);
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            break;
        case 5:
            if (registro[0].codigo != -1){
                mostrarLeiteAbate(registro);
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            break;
        case 6:
            if (registro[0].codigo != -1){
                mostrarAlimAbate(registro);         
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            break;
        case 7:
            if (registro[0].codigo != -1){
                cabecasAbate(registro);               
                break;
            } else{
                printf("Dados insuficientes!\n");
                break;
            }
            break;
        case 8:
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 8);
}

int main(){
    struct registro registro[QNTD_CABECAS];
    
    menu(registro);

}
