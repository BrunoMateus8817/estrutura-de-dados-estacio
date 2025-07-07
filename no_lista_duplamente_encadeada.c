// no_lista_duplamente_encadeada.c
// Definição de nó para lista duplamente encadeada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do elemento armazenado
typedef struct {
    char nome[50];
    int idade;
} Elemento;

// Estrutura do nó
typedef struct No {
    int chave;
    Elemento elemento;
    struct No *prox;
    struct No *ant;
} No;

int main() {
    // Aloca dois nós manualmente
    No *n1 = (No *) calloc(1, sizeof(No));
    No *n2 = (No *) calloc(1, sizeof(No));

    if (n1 == NULL || n2 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenchendo dados
    n1->chave = 10;
    strcpy(n1->elemento.nome, "Alice");
    n1->elemento.idade = 25;

    n2->chave = 20;
    strcpy(n2->elemento.nome, "Bob");
    n2->elemento.idade = 30;

    // Encadeando os nós
    n1->prox = n2;
    n1->ant = NULL;

    n2->prox = NULL;
    n2->ant = n1;

    // Impressão da lista do início ao fim
    printf("Percorrendo do início ao fim:\n");
    No *atual = n1;
    while (atual != NULL) {
        printf("Chave: %d, Nome: %s, Idade: %d\n",
               atual->chave,
               atual->elemento.nome,
               atual->elemento.idade);
        atual = atual->prox;
    }

    // Impressão da lista do fim ao início
    printf("\nPercorrendo do fim ao início:\n");
    atual = n2;
    while (atual != NULL) {
        printf("Chave: %d, Nome: %s, Idade: %d\n",
               atual->chave,
               atual->elemento.nome,
               atual->elemento.idade);
        atual = atual->ant;
    }

    // Libera memória
    free(n2);
    free(n1);

    return 0;
}
