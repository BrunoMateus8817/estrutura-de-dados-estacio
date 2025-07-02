#include <stdio.h>
#include <stdlib.h>

typedef struct departamento {
    int cod;
    char descricao[30];
} Departamento;

typedef struct cargo {
    int cod;
    char descricao[30];
} Cargo;

typedef struct funcionario {
    int cod;
    char nome[30];
    float salario;
    Departamento depto;
    Cargo cargo;
} Funcionario;

int main(void)
{
    Funcionario funcionario;

    printf("---- Cadastro de Funcionario ----\n\n");

    printf("Codigo do funcionario: ");
    scanf("%d", &funcionario.cod);
    getchar(); // limpa o \n deixado pelo scanf

    printf("Nome do funcionario: ");
    fgets(funcionario.nome, 30, stdin);

    printf("Salario do funcionario: ");
    scanf("%f", &funcionario.salario);
    getchar();

    printf("Codigo do departamento: ");
    scanf("%d", &funcionario.depto.cod);
    getchar();

    printf("Descricao do departamento: ");
    fgets(funcionario.depto.descricao, 30, stdin);

    printf("Codigo do cargo: ");
    scanf("%d", &funcionario.cargo.cod);
    getchar();

    printf("Descricao do cargo: ");
    fgets(funcionario.cargo.descricao, 30, stdin);

    printf("\n---- Dados do Funcionario ----\n");
    printf("Codigo: %d\n", funcionario.cod);
    printf("Nome: %s", funcionario.nome);
    printf("Salario: %.2f\n", funcionario.salario);

    printf("\n---- Departamento ----\n");
    printf("Codigo: %d\n", funcionario.depto.cod);
    printf("Descricao: %s", funcionario.depto.descricao);

    printf("\n---- Cargo ----\n");
    printf("Codigo: %d\n", funcionario.cargo.cod);
    printf("Descricao: %s", funcionario.cargo.descricao);

    system("pause");
    return 0;
}
