// lista_simplesmente_encadeada_no.c
// Definição de nó de lista simplesmente encadeada em C

#include <stdio.h>
#include <stdlib.h>

// Definição do nó
typedef struct No {
    int valor;             // Campo de dados
    struct No *prox;       // Ponteiro para o próximo nó
} No;

int main() {
    // Criação de dois nós manualmente
    No *primeiro = (No *) malloc(sizeof(No));
    No *segundo = (No *) malloc(sizeof(No));

    if (primeiro == NULL || segundo == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    primeiro->valor = 10;
    segundo->valor = 20;

    primeiro->prox = segundo; // Aponta para o próximo nó
    segundo->prox = NULL;     // Último nó aponta para NULL

    // Percorrendo a lista
    No *atual = primeiro;
    while (atual != NULL) {
        printf("Valor: %d\n", atual->valor);
        atual = atual->prox;
    }

    // Libera a memória
    free(segundo);
    free(primeiro);

    return 0;
}
