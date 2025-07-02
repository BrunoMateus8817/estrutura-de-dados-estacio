#include <stdio.h>
#include <stdlib.h>

struct departamento {
    int cod;
    char descricao[30];
};

struct cargo {
    int cod;
    char descricao[30];
};

struct funcionario {
    int cod;
    char nome[30];
    float salario;
    struct departamento depto;
    struct cargo cargo;
};

struct funcionario Funcionario;

int main(void)
{
    printf("---- Cadastro de Funcionario ----\n\n");

    printf("Codigo do funcionario: ");
    scanf("%d", &Funcionario.cod);
    getchar(); // limpa o \n deixado pelo scanf

    printf("Nome do funcionario: ");
    fgets(Funcionario.nome, 30, stdin);

    printf("Salario do funcionario: ");
    scanf("%f", &Funcionario.salario);
    getchar();

    printf("Codigo do departamento: ");
    scanf("%d", &Funcionario.depto.cod);
    getchar();

    printf("Descricao do departamento: ");
    fgets(Funcionario.depto.descricao, 30, stdin);

    printf("Codigo do cargo: ");
    scanf("%d", &Funcionario.cargo.cod);
    getchar();

    printf("Descricao do cargo: ");
    fgets(Funcionario.cargo.descricao, 30, stdin);

    printf("\n---- Dados do Funcionario ----\n");
    printf("Codigo: %d\n", Funcionario.cod);
    printf("Nome: %s", Funcionario.nome);
    printf("Salario: %.2f\n", Funcionario.salario);

    printf("\n---- Departamento ----\n");
    printf("Codigo: %d\n", Funcionario.depto.cod);
    printf("Descricao: %s", Funcionario.depto.descricao);

    printf("\n---- Cargo ----\n");
    printf("Codigo: %d\n", Funcionario.cargo.cod);
    printf("Descricao: %s", Funcionario.cargo.descricao);

    system("pause");
    return 0;
}
