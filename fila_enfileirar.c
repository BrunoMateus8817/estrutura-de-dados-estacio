// fila_enfileirar.c
// Função de enfileirar (enqueue) em fila estática circular em C

#include <stdio.h>
#include <string.h>

#define MAX_FILA 5

typedef struct {
    char nome[50];
    int idade;
} Elemento;

Elemento fila[MAX_FILA];
int inicio = -1;
int fim = -1;

// Função de enfileirar (enqueue)
int enfileirar(Elemento elemento) {
    // Verifica se a fila está cheia
    if (!((inicio == 0 && fim == MAX_FILA - 1) || (inicio == fim + 1))) {
        if (fim == MAX_FILA - 1 || fim == -1) {
            fila[0] = elemento;
            fim = 0;
            if (inicio == -1)
                inicio = 0;
        } else {
            fila[++fim] = elemento;
        }
        return 1; // sucesso
    } else {
        return 0; // falha, fila cheia
    }
}

// Exibe o estado atual da fila
void exibir_fila() {
    if (inicio == -1) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Estado atual da fila (inicio -> fim):\n");
    int i = inicio;
    while (1) {
        printf("Posição %d: Nome: %s, Idade: %d\n", i, fila[i].nome, fila[i].idade);
        if (i == fim)
            break;
        i = (i + 1) % MAX_FILA;
    }
}

int main() {
    Elemento e1 = {"Alice", 25};
    Elemento e2 = {"Bob", 30};
    Elemento e3 = {"Carol", 28};
    Elemento e4 = {"David", 35};
    Elemento e5 = {"Eve", 22};
    Elemento e6 = {"Frank", 40}; // Testa fila cheia

    // Enfileirando elementos
    if (enfileirar(e1))
        printf("Enfileirado: %s\n", e1.nome);
    else
        printf("Falha ao enfileirar %s\n", e1.nome);

    if (enfileirar(e2))
        printf("Enfileirado: %s\n", e2.nome);
    else
        printf("Falha ao enfileirar %s\n", e2.nome);

    if (enfileirar(e3))
        printf("Enfileirado: %s\n", e3.nome);
    else
        printf("Falha ao enfileirar %s\n", e3.nome);

    if (enfileirar(e4))
        printf("Enfileirado: %s\n", e4.nome);
    else
        printf("Falha ao enfileirar %s\n", e4.nome);

    if (enfileirar(e5))
        printf("Enfileirado: %s\n", e5.nome);
    else
        printf("Falha ao enfileirar %s\n", e5.nome);

    // Tentativa além da capacidade
    if (enfileirar(e6))
        printf("Enfileirado: %s\n", e6.nome);
    else
        printf("Falha ao enfileirar %s\n", e6.nome);

    printf("\n");
    exibir_fila();

    return 0;
}
