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

Aluno aluno;

int main() {
    setlocale(LC_ALL,"portuguese");

    aluno.codigo = 0;
    strcpy(aluno.nome, "NULL");
    aluno.datNasc.dia = 0;
    aluno.datNasc.mes = 0;
    aluno.datNasc.ano = 0;

    printf("\nO código do aluno é: %d", aluno.codigo);
    printf("\nO nome do aluno é: %s", aluno.nome);
    printf("\nA data de nascimento do aluno é: %d / %d / %d", aluno.datNasc.dia, aluno.datNasc.mes, aluno.datNasc.ano);

    printf("\n\nDigite o código do aluno: ");
    scanf("%d%*c", &aluno.codigo);

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0'; // remove o \n

    printf("Digite o dia do nascimento do aluno: ");
    scanf("%d%*c", &aluno.datNasc.dia);

    printf("Digite o mês do nascimento do aluno: ");
    scanf("%d%*c", &aluno.datNasc.mes);

    printf("Digite o ano do nascimento do aluno: ");
    scanf("%d%*c", &aluno.datNasc.ano);

    printf("\nO código do aluno é: %d", aluno.codigo);
    printf("\nO nome do aluno é: %s", aluno.nome);
    printf("\nA data de nascimento do aluno é: %d / %d / %d", aluno.datNasc.dia, aluno.datNasc.mes, aluno.datNasc.ano);

    printf("\n\nPressione ENTER para sair...");
    getchar();

    return 0;
}
