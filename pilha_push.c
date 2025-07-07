// pilha_push.c
// Função de empilhamento (push) em pilha estática em C

#include <stdio.h>
#include <string.h>

#define MAX_PILHA 5

typedef struct {
    char nome[50];
    int idade;
} Elemento;

Elemento pilha[MAX_PILHA];
int topo = -1; // Pilha vazia inicialmente

// Função de empilhamento
int push(Elemento elemento) {
    if (topo < (MAX_PILHA - 1)) {
        topo++;
        pilha[topo] = elemento;
        return 1; // Sucesso
    } else {
        return 0; // Falha, pilha cheia
    }
}

// Função para exibir a pilha
void exibir_pilha() {
    if (topo == -1) {
        printf("Pilha vazia.\n");
    } else {
        printf("Estado atual da pilha (topo -> base):\n");
        for (int i = topo; i >= 0; i--) {
            printf("Posição %d: Nome: %s, Idade: %d\n", i, pilha[i].nome, pilha[i].idade);
        }
    }
}

int main() {
    Elemento e1 = {"Alice", 25};
    Elemento e2 = {"Bob", 30};
    Elemento e3 = {"Carol", 28};
    Elemento e4 = {"David", 35};
    Elemento e5 = {"Eve", 22};
    Elemento e6 = {"Frank", 40}; // Exceder limite

    push(e1);
    push(e2);
    push(e3);
    push(e4);
    push(e5);

    if (!push(e6)) {
        printf("Falha ao empilhar: pilha cheia ao tentar empilhar %s.\n", e6.nome);
    }

    printf("\n");
    exibir_pilha();

    return 0;
}
