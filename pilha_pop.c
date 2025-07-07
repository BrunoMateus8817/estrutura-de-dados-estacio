// pilha_pop.c
// Função de desempilhamento (pop) em pilha estática em C

#include <stdio.h>
#include <string.h>

#define MAX_PILHA 5

typedef struct {
    char nome[50];
    int idade;
    int valido; // Usado para indicar se o elemento retornado pelo pop é válido
} Elemento;

Elemento pilha[MAX_PILHA];
int topo = -1; // Pilha inicialmente vazia

// Função de empilhamento (push)
int push(Elemento elemento) {
    if (topo < (MAX_PILHA - 1)) {
        topo++;
        pilha[topo] = elemento;
        return 1; // Sucesso
    } else {
        return 0; // Falha, pilha cheia
    }
}

// Função de desempilhamento (pop)
Elemento pop(void) {
    Elemento valor_recuperado;
    if (topo >= 0) {
        valor_recuperado = pilha[topo];
        topo--;
        valor_recuperado.valido = 1; // Indica sucesso
        return valor_recuperado;
    } else {
        valor_recuperado.valido = 0; // Indica falha
        return valor_recuperado;
    }
}

// Função para exibir a pilha
void exibir_pilha() {
    if (topo == -1) {
        printf("Pilha vazia.\n");
    } else {
        printf("Estado atual da pilha (topo -> base):\n");
        for (int i = topo; i >= 0; i--) {
            printf("Posição %d: Nome: %s, Idade: %d\n",
                   i, pilha[i].nome, pilha[i].idade);
        }
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
    for (int i = 0; i < 4; i++) { // Tenta desempilhar mais elementos do que empilhados
        Elemento retirado = pop();
        if (retirado.valido) {
            printf("Desempilhado: Nome: %s, Idade: %d\n", retirado.nome, retirado.idade);
        } else {
            printf("Falha ao desempilhar: pilha vazia.\n");
        }
    }

    printf("\nEstado final da pilha:\n");
    exibir_pilha();

    return 0;
}
