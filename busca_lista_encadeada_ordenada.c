// busca_lista_encadeada_ordenada.c
// Busca em lista encadeada ordenada em C

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *prox;
} No;

// Função de busca em lista encadeada ordenada
No *buscar(No *no_cabeca, No **aux, int chave) {
    No *atual = no_cabeca->prox;
    *aux = no_cabeca;

    while (atual != NULL) {
        if (atual->chave < chave) {
            *aux = atual;
            atual = atual->prox;
        } else if (atual->chave == chave) {
            return atual; // Elemento encontrado
        } else {
            return NULL; // Elemento não encontrado
        }
    }
    return NULL; // Lista vazia ou elemento não encontrado
}

int main() {
    // Criação de lista ordenada manualmente: 10 -> 20 -> 30
    No *cabeca = (No *) malloc(sizeof(No));
    cabeca->prox = NULL;

    No *n1 = (No *) malloc(sizeof(No));
    n1->chave = 10;
    n1->prox = NULL;

    No *n2 = (No *) malloc(sizeof(No));
    n2->chave = 20;
    n2->prox = NULL;

    No *n3 = (No *) malloc(sizeof(No));
    n3->chave = 30;
    n3->prox = NULL;

    // Encadeamento
    cabeca->prox = n1;
    n1->prox = n2;
    n2->prox = n3;

    int chave_busca = 20;
    No *aux = NULL;

    No *resultado = buscar(cabeca, &aux, chave_busca);

    if (resultado != NULL) {
        printf("Elemento %d encontrado no nó %p.\n", resultado->chave, (void *)resultado);
    } else {
        printf("Elemento %d não encontrado na lista.\n", chave_busca);
    }

    // Libera memória
    free(n3);
    free(n2);
    free(n1);
    free(cabeca);

    return 0;
}
