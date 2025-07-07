// busca_binaria.c
// Exemplo de busca binária recursiva em C

#include <stdio.h>

// Função de busca binária recursiva
int busca_binaria(int lista[], int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (lista[meio] == elemento) {
        return meio; // Elemento encontrado
    } else if (elemento < lista[meio]) {
        return busca_binaria(lista, elemento, inicio, meio - 1);
    } else {
        return busca_binaria(lista, elemento, meio + 1, fim);
    }
}

int main() {
    int lista[] = {10, 20, 30, 40, 50, 60, 70};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int elemento = 40;

    int resultado = busca_binaria(lista, elemento, 0, tamanho - 1);

    if (resultado != -1) {
        printf("Elemento %d encontrado na posição %d.\n", elemento, resultado);
    } else {
        printf("Elemento %d não encontrado na lista.\n", elemento);
    }

    return 0;
}
