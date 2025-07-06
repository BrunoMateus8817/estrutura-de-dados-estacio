// remocao_sequencial.c
// Exemplo de remoção sequencial em C

#include <stdio.h>

#define MAX 10

typedef struct {
    int chave;
} Item;

int buscar(Item Lista[], int chave, int n) {
    for (int i = 0; i < n; i++) {
        if (Lista[i].chave == chave) {
            return i; // Retorna a posição onde encontrou
        }
    }
    return n; // Retorna n se não encontrou
}

int remover(Item Lista[], int chave, int *n) {
    if (*n > 0) {
        int i = buscar(Lista, chave, *n);
        if (i < *n) { // Se encontrou
            for (int a = i; a < *n - 1; a++) {
                Lista[a] = Lista[a + 1]; // Desloca elementos
            }
            (*n)--; // Diminui o tamanho lógico
            return 1; // Remoção realizada
        } else {
            return -1; // Elemento não encontrado
        }
    } else {
        printf("Erro: lista vazia.\n");
        return -2; // Lista vazia
    }
}

int main() {
    Item Lista[MAX] = { {10}, {20}, {30}, {40}, {50} };
    int n = 5; // Quantidade atual de elementos

    int chave_remover = 30;

    int resultado = remover(Lista, chave_remover, &n);

    if (resultado == 1) {
        printf("Elemento %d removido com sucesso.\n", chave_remover);
    } else if (resultado == -1) {
        printf("Elemento %d não encontrado na lista.\n", chave_remover);
    }

    // Exibe a lista após a remoção
    printf("Lista atual:\n");
    for (int i = 0; i < n; i++) {
        printf("Posição %d: %d\n", i, Lista[i].chave);
    }

    return 0;
}
