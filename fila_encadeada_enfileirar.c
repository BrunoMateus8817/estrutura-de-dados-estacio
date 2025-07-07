// fila_encadeada_enfileirar.c
// Função de enfileirar (enqueue) em fila encadeada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elemento armazenado na fila
typedef struct {
    char nome[50];
    int idade;
} Elemento;

// Estrutura do nó da fila
typedef struct No {
    Elemento elemento;
    struct No *prox;
} No;

No *inicio = NULL;
No *fim = NULL;

// Função de enfileirar (enqueue)
int enfileirar(Elemento elemento) {
    No *novo_no = (No *) calloc(1, sizeof(No));
    if (novo_no != NULL) {
        novo_no->elemento = elemento;
        novo_no->prox = NULL;

        if (fim != NULL) {
            fim->prox = novo_no;
        } else {
            inicio = novo_no;
        }
        fim = novo_no;
        return 1; // sucesso
    } else {
        return 0; // falha
    }
}

// Exibe o estado atual da fila
void exibir_fila() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Estado atual da fila (inicio -> fim):\n");
    No *atual = inicio;
    int pos = 0;
    while (atual != NULL) {
        printf("Posição %d: Nome: %s, Idade: %d\n", pos, atual->elemento.nome, atual->elemento.idade);
        atual = atual->prox;
        pos++;
    }
}

// Libera a memória da fila
void liberar_fila() {
    while (inicio != NULL) {
        No *temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
    fim = NULL;
}

int main() {
    Elemento e1 = {"Alice", 25};
    Elemento e2 = {"Bob", 30};
    Elemento e3 = {"Carol", 28};

    if (enfileirar(e1))
        printf("Enfileirado: %s\n", e1.nome);
    else
        printf("Falha ao enfileirar %s\n", e1.nome);

    if (enfileirar(e2))
        printf("Enfileirado: %s\n", e2.nome);
    else
        printf("Falha ao enfileirar %s\n", e2.nome);

    if (enfileirar(e3))
        printf("Enfileirado: %s\n", e3.nome);
    else
        printf("Falha ao enfileirar %s\n", e3.nome);

    printf("\n");
    exibir_fila();

    liberar_fila();
    return 0;
}
