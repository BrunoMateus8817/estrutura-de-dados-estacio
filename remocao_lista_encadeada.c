// remocao_lista_encadeada.c
// Remoção em lista encadeada ordenada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Elemento
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

// Função de busca utilizada para inserção/remoção
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

// Função de remoção em lista encadeada ordenada
int remover(No *no_cabeca, int chave) {
    No *aux, *anterior = no_cabeca;
    aux = buscar(no_cabeca, &anterior, chave);

    if (aux != NULL) {
        anterior->prox = aux->prox;
        free(aux);
        return 1; // Remoção bem-sucedida
    } else {
        return 0; // Falha na remoção
    }
}

// Função para exibir a lista
void exibir_lista(No *no_cabeca) {
    No *atual = no_cabeca->prox;
    while (atual != NULL) {
        printf("Chave: %d, Nome: %s, Idade: %d\n",
               atual->chave,
               atual->elemento.nome,
               atual->elemento.idade);
        atual = atual->prox;
    }
}

int main() {
    // Cabeça da lista
    No *cabeca = (No *) calloc(1, sizeof(No));
    cabeca->prox = NULL;

    // Elementos
    Elemento e1 = {"Alice", 25};
    Elemento e2 = {"Bob", 30};
    Elemento e3 = {"Carol", 28};

    // Inserção direta para simplificação do exemplo
    No *n1 = (No *) calloc(1, sizeof(No));
    n1->chave = 10;
    n1->elemento = e1;

    No *n2 = (No *) calloc(1, sizeof(No));
    n2->chave = 20;
    n2->elemento = e2;

    No *n3 = (No *) calloc(1, sizeof(No));
    n3->chave = 30;
    n3->elemento = e3;

    // Encadeamento
    cabeca->prox = n1;
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;

    printf("Lista antes da remoção:\n");
    exibir_lista(cabeca);

    int chave_remover = 20;
    if (remover(cabeca, chave_remover)) {
        printf("\nElemento com chave %d removido com sucesso.\n", chave_remover);
    } else {
        printf("\nFalha ao remover elemento com chave %d.\n", chave_remover);
    }

    printf("\nLista após a remoção:\n");
    exibir_lista(cabeca);

    // Liberação de memória
    No *atual = cabeca;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
