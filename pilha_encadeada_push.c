// pilha_encadeada_push.c
// Função de empilhamento (push) em pilha encadeada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elemento armazenado na pilha
typedef struct {
    char nome[50];
    int idade;
} Elemento;

// Estrutura do nó da pilha
typedef struct No {
    Elemento elemento;
    struct No *prox;
} No;

No *topo = NULL; // Pilha inicialmente vazia

// Função de empilhamento (push)
int push(Elemento elemento) {
    No *novo_no = (No *) calloc(1, sizeof(No));
    if (novo_no != NULL) {
        novo_no->elemento = elemento;
        novo_no->prox = topo;
        topo = novo_no;
        return 1; // Sucesso
    } else {
        return 0; // Falha
    }
}

// Função para exibir a pilha
void exibir_pilha() {
    if (topo == NULL) {
        printf("Pilha vazia.\n");
    } else {
        printf("Estado atual da pilha (topo -> base):\n");
        No *atual = topo;
        int pos = 0;
        while (atual != NULL) {
            printf("Posição %d: Nome: %s, Idade: %d\n", pos, atual->elemento.nome, atual->elemento.idade);
            atual = atual->prox;
            pos++;
        }
    }
}

// Libera toda a memória alocada pela pilha
void liberar_pilha() {
    while (topo != NULL) {
        No *temp = topo;
        topo = topo->prox;
        free(temp);
    }
}

int main() {
    Elemento e1 = {"Alice", 25};
    Elemento e2 = {"Bob", 30};
    Elemento e3 = {"Carol", 28};

    if (push(e1))
        printf("Empilhado: %s\n", e1.nome);
    else
        printf("Falha ao empilhar %s\n", e1.nome);

    if (push(e2))
        printf("Empilhado: %s\n", e2.nome);
    else
        printf("Falha ao empilhar %s\n", e2.nome);

    if (push(e3))
        printf("Empilhado: %s\n", e3.nome);
    else
        printf("Falha ao empilhar %s\n", e3.nome);

    printf("\n");
    exibir_pilha();

    liberar_pilha(); // Limpeza

    return 0;
}
