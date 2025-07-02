#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char nome[200];
    Data datNasc;
} Aluno;

Aluno aluno[5];

int main() {
    setlocale(LC_ALL, "portuguese");

    for(int i = 0; i < 5; i++) {
        aluno[i].codigo = 0;
        strcpy(aluno[i].nome, "NULL");
        aluno[i].datNasc.dia = 0;
        aluno[i].datNasc.mes = 0;
        aluno[i].datNasc.ano = 0;
    }

    printf("\n================== Dados Iniciais ==================\n");
    for(int i = 0; i < 5; i++) {
        printf("\nAluno %d:", i + 1);
        printf("\nCódigo: %d", aluno[i].codigo);
        printf("\nNome: %s", aluno[i].nome);
        printf("\nData de Nascimento: %d/%d/%d\n",
               aluno[i].datNasc.dia, aluno[i].datNasc.mes, aluno[i].datNasc.ano);
    }

    for(int i = 0; i < 5; i++) {
        printf("\n=====================================================");
        printf("\nCadastro do aluno %d", i + 1);

        printf("\nDigite o código do aluno: ");
        scanf("%d%*c", &aluno[i].codigo);

        printf("Digite o nome do aluno: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        aluno[i].nome[strcspn(aluno[i].nome, "\n")] = '\0'; // remove \n

        printf("Digite o dia do nascimento do aluno: ");
        scanf("%d%*c", &aluno[i].datNasc.dia);

        printf("Digite o mês do nascimento do aluno: ");
        scanf("%d%*c", &aluno[i].datNasc.mes);

        printf("Digite o ano do nascimento do aluno: ");
        scanf("%d%*c", &aluno[i].datNasc.ano);
    }

    printf("\n================== Dados Finais ==================\n");
    for(int i = 0; i < 5; i++) {
        printf("\nAluno %d:", i + 1);
        printf("\nCódigo: %d", aluno[i].codigo);
        printf("\nNome: %s", aluno[i].nome);
        printf("\nData de Nascimento: %d/%d/%d\n",
               aluno[i].datNasc.dia, aluno[i].datNasc.mes, aluno[i].datNasc.ano);
    }

    printf("\nPressione ENTER para sair...");
    getchar();

    return 0;
}
