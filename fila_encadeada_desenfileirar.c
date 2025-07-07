// fila_encadeada_desenfileirar.c
// Função de desenfileirar (dequeue) em fila encadeada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elemento armazenado na fila
typedef struct {
    char nome[50];
    int idade;
    int valido; // 1 = sucesso, 0 = falha
} Elemento;

// Estrutura do nó
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
        return 1;
    } else {
        return 0;
    }
}

// Função de desenfileirar (dequeue)
Elemento desenfileirar(void) {
    Elemento elemento_recuperado;
    No *aux = inicio;

    if (inicio != NULL) {
        elemento_recuperado = aux->elemento;
        elemento_recuperado.valido = 1; // sucesso

        inicio = inicio->prox;
        if (inicio == NULL) {
            fim = NULL;
        }

        free(aux);
    } else {
        elemento_recuperado.valido = 0; // falha
    }

    return elemento_recuperado;
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
        printf("Posição %d: Nome: %s, Idade: %d\n",
               pos, atual->elemento.nome, atual->elemento.idade);
        atual = atual->prox;
        pos++;
    }
}

// Libera toda a memória da fila
void liberar_fila() {
    while (inicio != NULL) {
        No *temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
    fim = NULL;
}

int main() {
    Elemento e1 = {"Alice", 25, 1};
    Elemento e2 = {"Bob", 30, 1};
    Elemento e3 = {"Carol", 28, 1};

    enfileirar(e1);
    enfileirar(e2);
    enfileirar(e3);

    printf("Fila após enfileiramento:\n");
    exibir_fila();

    printf("\nDesenfileirando elementos:\n");
    for (int i = 0; i < 4; i++) { // Testa fila vazia também
        Elemento removido = desenfileirar();
        if (removido.valido) {
            printf("Desenfileirado: Nome: %s, Idade: %d\n", removido.nome, removido.idade);
        } else {
            printf("Falha ao desenfileirar: fila vazia.\n");
        }
    }

    printf("\nEstado final da fila:\n");
    exibir_fila();

    liberar_fila();
    return 0;
}
