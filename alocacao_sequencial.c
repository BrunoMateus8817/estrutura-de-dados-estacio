// alocacao_sequencial.c
// Exemplo simples de alocação sequencial em C

#include <stdio.h>

int main() {
    int vetor[10];      // Aloca 10 posições consecutivas na memória
    int a = 50;         // Cria uma variável com valor 50

    vetor[3] = a;       // Armazena o valor de 'a' na 4ª posição do vetor (índice 3)

    // Exibe o valor armazenado para conferência
    printf("O valor na posição 3 do vetor é: %d\n", vetor[3]);

    return 0;
}