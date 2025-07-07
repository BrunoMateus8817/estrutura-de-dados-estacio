// fila_desenfileirar.c
// Função de desenfileirar (dequeue) em fila estática circular em C

#include <stdio.h>
#include <string.h>

#define MAX_FILA 5

typedef struct {
    char nome[50];
    int idade;
    int valido; // 1 = sucesso, 0 = falha
} Elemento;

Elemento fila[MAX_FILA];
int inicio = -1;
int fim = -1;

// Função de enfileirar (enqueue)
int enfileirar(Elemento elemento) {
    if (!((inicio == 0 && fim == MAX_FILA - 1) || (inicio == fim + 1))) {
        if (fim == MAX_FILA - 1 || fim == -1) {
            fila[0] = elemento;
            fim = 0;
            if (inicio == -1)
                inicio = 0;
        } else {
            fila[++fim] = elemento;
        }
        return 1;
    } else {
        return 0; // fila cheia
    }
}

// Função de desenfileirar (dequeue)
Elemento desenfileirar(void) {
    Elemento elem_temp;
    if (inicio != -1) {
        elem_temp = fila[inicio];
        elem_temp.valido = 1; // sucesso
        if (inicio == fim) { // último elemento
            inicio = fim = -1;
        } else if (inicio == MAX_FILA - 1) {
            inicio = 0;
        } else {
            inicio++;
        }
    } else {
        elem_temp.valido = 0; // falha, fila vazia
    }
    return elem_temp;
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
    Elemento e1 = {"Alice", 25, 1};
    Elemento e2 = {"Bob", 30, 1};
    Elemento e3 = {"Carol", 28, 1};

    enfileirar(e1);
    enfileirar(e2);
    enfileirar(e3);

    printf("Fila após enfileiramento:\n");
    exibir_fila();

    printf("\nDesenfileirando elementos:\n");
    for (int i = 0; i < 4; i++) { // Testa mais remoções que elementos para checar fila vazia
        Elemento removido = desenfileirar();
        if (removido.valido) {
            printf("Desenfileirado: Nome: %s, Idade: %d\n", removido.nome, removido.idade);
        } else {
            printf("Falha ao desenfileirar: fila vazia.\n");
        }
    }

    printf("\nEstado final da fila:\n");
    exibir_fila();

    return 0;
}
