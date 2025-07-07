// insercao_lista_encadeada.c
// Inserção em lista encadeada ordenada em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de Elemento armazenado no nó
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

// Função de busca (já implementada anteriormente)
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
    return NULL;
}

// Função de inserção em lista encadeada ordenada
int inserir(No *no_cabeca, Elemento novo_elemento, int chave) {
    No *aux, *anterior = no_cabeca;
    No *novo_no = (No *) calloc(1, sizeof(No));
    aux = buscar(no_cabeca, &anterior, chave);

    if ((novo_no == NULL) || (aux != NULL)) {
        return 0; // Falha na inserção
    } else {
        novo_no->elemento = novo_elemento;
        novo_no->chave = chave;
        novo_no->prox = anterior->prox;
        anterior->prox = novo_no;
        return 1; // Inserção bem-sucedida
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
    // Cria cabeça da lista
    No *cabeca = (No *) calloc(1, sizeof(No));
    cabeca->prox = NULL;

    // Cria elemento para inserir
    Elemento e1;
    strcpy(e1.nome, "Alice");
    e1.idade = 25;

    Elemento e2;
    strcpy(e2.nome, "Bob");
    e2.idade = 30;

    Elemento e3;
    strcpy(e3.nome, "Carol");
    e3.idade = 28;

    // Inserções
    if (inserir(cabeca, e2, 20))
        printf("Inserido: Bob (20)\n");
    else
        printf("Falha ao inserir Bob\n");

    if (inserir(cabeca, e1, 10))
        printf("Inserido: Alice (10)\n");
    else
        printf("Falha ao inserir Alice\n");

    if (inserir(cabeca, e3, 30))
        printf("Inserido: Carol (30)\n");
    else
        printf("Falha ao inserir Carol\n");

    printf("\nLista final:\n");
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
