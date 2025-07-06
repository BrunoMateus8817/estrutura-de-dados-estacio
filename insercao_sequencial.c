// insercao_sequencial.c
// Exemplo de inserção sequencial em C

#include <stdio.h>

#define MAX 10

typedef struct {
    int chave;
} Item;

int buscar(Item Lista[], int chave, int n) {
    for (int i = 0; i < n; i++) {
        if (Lista[i].chave == chave) {
            return i; // Encontrou, retorna posição
        }
    }
    return n; // Não encontrou
}

int inserir(Item Lista[], Item novo_elemento, int *n) {
    if (buscar(Lista, novo_elemento.chave, *n) == *n) {
        if (*n < MAX) {
            Lista[*n] = novo_elemento;
            (*n)++;
            return 1; // Inserção realizada
        } else {
            return -2; // Lista cheia
        }
    }
    return -1; // Chave já existe
}

int main() {
    Item Lista[MAX] = { {10}, {20}, {30} };
    int n = 3; // Número atual de elementos

    Item novo_elemento;
    novo_elemento.chave = 40;

    int resultado = inserir(Lista, novo_elemento, &n);

    if (resultado == 1) {
        printf("Elemento %d inserido com sucesso.\n", novo_elemento.chave);
    } else if (resultado == -1) {
        printf("Chave %d já existe na lista.\n", novo_elemento.chave);
    } else if (resultado == -2) {
        printf("Lista cheia. Não foi possível inserir %d.\n", novo_elemento.chave);
    }

    // Exibe a lista atual
    printf("Lista atual:\n");
    for (int i = 0; i < n; i++) {
        printf("Posição %d: %d\n", i, Lista[i].chave);
    }

    return 0;
}
