// lista_encadeada_no_simples.c
// Definição simples de nó para lista simplesmente encadeada em C

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar o elemento armazenado no nó
typedef struct {
    char nome[50];
    int idade;
} Elemento;

// Estrutura do nó
typedef struct No {
    int chave;
    Elemento elemento;
    struct No *prox;
} No;

int main() {
    // Cria dois nós manualmente
    No *primeiro = (No *) malloc(sizeof(No));
    No *segundo = (No *) malloc(sizeof(No));

    if (primeiro == NULL || segundo == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preenchendo dados do primeiro nó
    primeiro->chave = 1;
    primeiro->elemento.idade = 25;
    snprintf(primeiro->elemento.nome, sizeof(primeiro->elemento.nome), "Alice");

    // Preenchendo dados do segundo nó
    segundo->chave = 2;
    segundo->elemento.idade = 30;
    snprintf(segundo->elemento.nome, sizeof(segundo->elemento.nome), "Bob");

    // Encadeamento
    primeiro->prox = segundo;
    segundo->prox = NULL;

    // Percorrendo a lista
    No *atual = primeiro;
    while (atual != NULL) {
        printf("Chave: %d, Nome: %s, Idade: %d\n",
               atual->chave,
               atual->elemento.nome,
               atual->elemento.idade);
        atual = atual->prox;
    }

    // Liberando memória
    free(segundo);
    free(primeiro);

    return 0;
}
