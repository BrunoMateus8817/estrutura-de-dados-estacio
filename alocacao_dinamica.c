// alocacao_dinamica.c
// Exemplo de alocação dinâmica de vetor em C

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;
    int tamanho_vetor;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    vetor = (int *) malloc(tamanho_vetor * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Encerra o programa em caso de erro
    }

    // Preenche o vetor
    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i] = i * 10; // Exemplo de preenchimento
    }

    // Exibe os valores armazenados
    printf("Valores armazenados no vetor:\n");
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // Libera a memória alocada
    free(vetor);

    return 0;
}
