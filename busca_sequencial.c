// busca_sequencial.c
// Exemplo de busca sequencial em C

#include <stdio.h>

#define N 5  // Tamanho da lista

typedef struct {
    int chave;
} Item;

int buscar(Item Lista[], int chave, int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++) { // i de 0 até n-1
            if (Lista[i].chave == chave) {
                return i; // Retorna a posição onde encontrou
            }
        }
    }
    return n; // Retorna n indicando que não encontrou
}

int main() {
    Item Lista[N] = { {10}, {20}, {30}, {40}, {50} };
    int chave = 30;

    int posicao = buscar(Lista, chave, N);

    if (posicao != N) {
        printf("Chave %d encontrada na posição %d.\n", chave, posicao);
    } else {
        printf("Chave %d não encontrada na lista.\n", chave);
    }

    return 0;
}
