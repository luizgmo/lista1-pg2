#include <stdio.h>
#include <string.h>

#define N 100

struct endereco{
    char rua[20];
    int numero;
    char comp[20];
    char bairro[20];
    int cep;
    char cidade[20];
    char estado[3];
    char pais[10];
};

struct telefone{
    int ddd;
    int numero;
};

struct nasc{
    int dia;
    int mes;
    int ano;
};

struct pessoa{
    char nome[20];
    char email[20];
    struct endereco endereco;
    struct telefone telefone;
    struct nasc nasc;
    char obs[40];
};

int inserirPessoa(struct pessoa agenda[], int quantidade){
    int i, j;
    struct pessoa novaPessoa;

    printf("Digite o nome: ");
    gets(novaPessoa.nome);

    printf("Digite o email: ");
    gets(novaPessoa.email);

    printf("Digite a rua: ");
    gets(novaPessoa.endereco.rua);

    do{
        printf("Digite o número da residência: ");
        scanf("%d", &novaPessoa.endereco.numero);
        if(novaPessoa.endereco.numero < 0){
            printf("Número inválido!\n");
        }
    } while(novaPessoa.endereco.numero < 0);
    getchar();

    printf("Digite o complemento: ");
    gets(novaPessoa.endereco.comp);

    printf("Digite o bairro: ");
    gets(novaPessoa.endereco.bairro);

    do{
        printf("Digite o CEP: ");
        scanf("%d", &novaPessoa.endereco.cep);
        if(novaPessoa.endereco.cep < 0){
            printf("CEP inválido!\n");
        }
    } while(novaPessoa.endereco.cep < 0);
    getchar();

    printf("Digite a cidade: ");
    gets(novaPessoa.endereco.cidade);

    printf("Digite o estado: ");
    gets(novaPessoa.endereco.estado);

    printf("Digite o país: ");
    gets(novaPessoa.endereco.pais);

    do{
        printf("Digite o DDD do telefone: ");
        scanf("%d", &novaPessoa.telefone.ddd);
        if(novaPessoa.telefone.ddd < 10 || novaPessoa.telefone.ddd > 99){
            printf("DDD inválido!\n");
        }
    } while(novaPessoa.telefone.ddd < 10 || novaPessoa.telefone.ddd > 99);
    getchar();

    do{
        printf("Digite o número do telefone: ");
        scanf("%d", &novaPessoa.telefone.numero);
        if(novaPessoa.telefone.numero < 0){
            printf("Número de telefone inválido!\n");
        }
    } while(novaPessoa.telefone.numero < 0);
    getchar();

    do{
        printf("Digite o dia de nascimento (1 - 30): ");
        scanf("%d", &novaPessoa.nasc.dia);
        if(novaPessoa.nasc.dia < 1 || novaPessoa.nasc.dia > 30){
            printf("Dia inválido!\n");
        }
    } while(novaPessoa.nasc.dia < 1 || novaPessoa.nasc.dia > 30);

    do{
        printf("Digite o mês de nascimento (1 - 12): ");
        scanf("%d", &novaPessoa.nasc.mes);
        if(novaPessoa.nasc.mes < 1 || novaPessoa.nasc.mes > 12){
            printf("Mês inválido!\n");
        }
    } while(novaPessoa.nasc.mes < 1 || novaPessoa.nasc.mes > 12);

    do{
        printf("Digite o ano de nascimento: ");
        scanf("%d", &novaPessoa.nasc.ano);
        if(novaPessoa.nasc.ano < 1900 || novaPessoa.nasc.ano > 2024){
            printf("Ano inválido!\n");
        }
    } while(novaPessoa.nasc.ano < 1900 || novaPessoa.nasc.ano > 2024);
    getchar();

    printf("Digite sua observação: ");
    gets(novaPessoa.obs);

    for (i = 0; i < quantidade; i++) {
        if (strcmp(novaPessoa.nome, agenda[i].nome) < 0) {
            break;
        }
    }

    for (j = quantidade; j > i; j--) {
        agenda[j] = agenda[j - 1];
    }

    agenda[i] = novaPessoa;

    return quantidade + 1;
}

int removerPessoa(struct pessoa agenda[], int quantidade) {
    char nome[20];
    int i, j;
    int encontrado = 0;

    printf("Digite o nome da pessoa a ser removida: ");
    gets(nome);

    for (i = 0; i < quantidade; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            encontrado = 1;
            for (j = i; j < quantidade - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            quantidade--;
            break;
        }
    }

    if (encontrado) {
        printf("Pessoa removida com sucesso!\n");
    } else {
        printf("Pessoa não encontrada!\n");
    }
    return quantidade;
}

void imprimirDados(struct pessoa agenda[], int quantidade){
    int i, opcao = 0;

    printf("\n1 - Imprimir nome, telefone e e-mail\n");
    printf("2 - Imprimir todos os dados\n");
    do {
        printf("Escolha uma opção válida: ");
        scanf("%d", &opcao);
    } while (opcao != 1 && opcao != 2);

    if (opcao == 1){
        for (i = 0; i < quantidade; i++){
            printf("\n--- Dados da Pessoa %d ---\n", i + 1);
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: (%d) %d\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Email: %s\n", agenda[i].email);
        }
    } else{
        for (i = 0; i < quantidade; i++){
        printf("\n--- Dados da Pessoa %d ---\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Email: %s\n", agenda[i].email);
        printf("Rua: %s\n", agenda[i].endereco.rua);
        printf("Número da residência: %d\n", agenda[i].endereco.numero);
        printf("Complemento: %s\n", agenda[i].endereco.comp);
        printf("Bairro: %s\n", agenda[i].endereco.bairro);
        printf("CEP: %d\n", agenda[i].endereco.cep);
        printf("Cidade: %s\n", agenda[i].endereco.cidade);
        printf("Estado: %s\n", agenda[i].endereco.estado);
        printf("País: %s\n", agenda[i].endereco.pais);
        printf("Telefone: (%d) %d\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
        printf("Data de nascimento: %02d/%02d/%04d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
        printf("Observação: %s\n", agenda[i].obs);
    }
    }

}

void buscarPrimeiroNome(struct pessoa agenda[], int quantidade){
    int i;
    char nome[20];
    char primeiroNome[20];
    char nomeCopia[50];
    int encontrou = 0;

    printf("Digite o primeiro nome que deseja filtrar: ");
    gets(nome);
    nome[strcspn(nome, "\n")] = 0;

    for(i = 0; i < quantidade; i++){
        strcpy(nomeCopia, agenda[i].nome);
        strcpy(primeiroNome, strtok(nomeCopia, " "));

        if (strcmp(primeiroNome, nome) == 0){
            encontrou = 1;
            printf("\n--- Dados da pessoa com o nome digitado ---\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número da residência: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.comp);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %d\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: (%d) %d\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de nascimento: %02d/%02d/%04d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
            printf("Observação: %s\n", agenda[i].obs);
        }
    }

    if (!encontrou) {
        printf("\nNenhuma pessoa foi encontrada.\n");
    }
}

void buscarMesAniversario(struct pessoa agenda[]){
    int i, mes;
    int encontrou = 0;
    
    do{
        printf("Digite o mês de aniversário (1 - 12): ");
        scanf("%d", &mes);
        if(mes < 1 || mes > 12){
            printf("Mês inválido!\n");
        }
    } while(mes < 1 || mes > 12);

    for (i = 0; i < N; i++){
        if (agenda[i].nasc.mes == mes){
            encontrou = 1;
            printf("\n--- Dados da pessoa do mês digitado ---\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número da residência: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.comp);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %d\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: (%d) %d\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de nascimento: %02d/%02d/%04d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
            printf("Observação: %s\n", agenda[i].obs);
        }
    }

    if (!encontrou) {
        printf("\nNenhuma pessoa foi encontrada.\n");
    }
}

void buscarDiaMesAniversario(struct pessoa agenda[]){
    int i, mes, dia;
    int encontrou = 0;
    
    do{
        printf("Digite o dia de aniversário (1 - 30): ");
        scanf("%d", &dia);
        if(dia < 1 || dia > 30){
            printf("Dia inválido!\n");
        }
    } while(dia < 1 || dia > 30);

    do{
        printf("Digite o mês de aniversário (1 - 12): ");
        scanf("%d", &mes);
        if(mes < 1 || mes > 12){
            printf("Mês inválido!\n");
        }
    } while(mes < 1 || mes > 12);

    for (i = 0; i < N; i++){
        if (agenda[i].nasc.mes == mes && agenda[i].nasc.dia == dia){
            encontrou = 1;
            printf("\n--- Dados da pessoa do dia e mês digitado ---\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Email: %s\n", agenda[i].email);
            printf("Rua: %s\n", agenda[i].endereco.rua);
            printf("Número da residência: %d\n", agenda[i].endereco.numero);
            printf("Complemento: %s\n", agenda[i].endereco.comp);
            printf("Bairro: %s\n", agenda[i].endereco.bairro);
            printf("CEP: %d\n", agenda[i].endereco.cep);
            printf("Cidade: %s\n", agenda[i].endereco.cidade);
            printf("Estado: %s\n", agenda[i].endereco.estado);
            printf("País: %s\n", agenda[i].endereco.pais);
            printf("Telefone: (%d) %d\n", agenda[i].telefone.ddd, agenda[i].telefone.numero);
            printf("Data de nascimento: %02d/%02d/%04d\n", agenda[i].nasc.dia, agenda[i].nasc.mes, agenda[i].nasc.ano);
            printf("Observação: %s\n", agenda[i].obs);
        }
    }

    if (!encontrou) {
        printf("\nNenhuma pessoa foi encontrada.\n");
    }
}

void menu(struct pessoa agenda[], int quantidade){
    int op = 0;

    do {
        printf("\n1 - Inserir pessoa\n");
        printf("2 - Remover pessoa\n");
        printf("3 - Buscar por primeiro nome\n");
        printf("4 - Buscar por mês de aniversário\n");
        printf("5 - Buscar por dia e mês de aniversário\n");
        printf("6 - Exibir dados\n");
        printf("7 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &op);
        getchar();

        switch (op){
        case 1:
            quantidade = inserirPessoa(agenda, quantidade);
            break;
        case 2:
            quantidade = removerPessoa(agenda, quantidade);
            break;
        case 3:
            buscarPrimeiroNome(agenda, quantidade);
            break;
        case 4:
            buscarMesAniversario(agenda);
            break;
        case 5:
            buscarDiaMesAniversario(agenda);
            break;
        case 6:
            imprimirDados(agenda, quantidade);
            break;
        case 7:
            break;
            
        }
    } while (op != 7);
}

int main(){
    struct pessoa agenda[N];
    int quantidade = 0;

    menu(agenda, quantidade);
    
}