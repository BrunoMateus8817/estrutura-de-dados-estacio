// pilha_encadeada_pop.c
// Função de desempilhamento (pop) em pilha encadeada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de elemento
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

// Função de desempilhamento (pop)
Elemento pop(void) {
    Elemento elemento_recuperado;
    if (topo != NULL) {
        No *aux = topo;
        elemento_recuperado = topo->elemento;
        elemento_recuperado.valido = 1; // sucesso
        topo = topo->prox;
        free(aux);
    } else {
        elemento_recuperado.valido = 0; // falha
    }
    return elemento_recuperado;
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

// Libera a memória da pilha
void liberar_pilha() {
    while (topo != NULL) {
        No *temp = topo;
        topo = topo->prox;
        free(temp);
    }
}

int main() {
    Elemento e1 = {"Alice", 25, 1};
    Elemento e2 = {"Bob", 30, 1};
    Elemento e3 = {"Carol", 28, 1};

    push(e1);
    push(e2);
    push(e3);

    printf("Pilha após empilhamento:\n");
    exibir_pilha();

    printf("\nDesempilhando elementos:\n");
    for (int i = 0; i < 4; i++) { // Desempilha mais vezes para testar pilha vazia
        Elemento retirado = pop();
        if (retirado.valido) {
            printf("Desempilhado: Nome: %s, Idade: %d\n", retirado.nome, retirado.idade);
        } else {
            printf("Falha ao desempilhar: pilha vazia.\n");
        }
    }

    printf("\nEstado final da pilha:\n");
    exibir_pilha();

    liberar_pilha();
    return 0;
}
