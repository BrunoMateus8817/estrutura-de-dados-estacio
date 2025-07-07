// ordenacao_por_distribuicao.c
// Implementação simplificada de ordenação por distribuição (Radix Sort) em C

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Função para obter o dígito na posição específica
int obter_digito(int numero, int pos) {
    while (pos-- > 0)
        numero /= 10;
    return numero % 10;
}

// Função principal de ordenação por distribuição
void ordenacaoPorDistribuicao(int m, int n, int Entrada[]) {
    int i, j, k, digito, maior = Entrada[0];
    int Fila[10][MAX], FilaCount[10];

    // Descobre o maior elemento para definir o número de dígitos
    for (i = 1; i < n; i++)
        if (Entrada[i] > maior)
            maior = Entrada[i];

    int num_passos = 0;
    while (maior > 0) {
        num_passos++;
        maior /= 10;
    }

    int exp = 1;
    for (i = 0; i < num_passos; i++) {
        for (k = 0; k < 10; k++)
            FilaCount[k] = 0;

        for (j = 0; j < n; j++) {
            digito = (Entrada[j] / exp) % 10;
            Fila[digito][FilaCount[digito]++] = Entrada[j];
        }

        j = 0;
        for (k = 0; k < 10; k++) {
            for (int p = 0; p < FilaCount[k]; p++)
                Entrada[j++] = Fila[k][p];
        }

        exp *= 10;
    }
}

void exibir(int Entrada[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", Entrada[i]);
    printf("\n");
}

int main() {
    int Entrada[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(Entrada) / sizeof(Entrada[0]);

    printf("Vetor original:\n");
    exibir(Entrada, n);

    ordenacaoPorDistribuicao(10, n, Entrada);

    printf("Vetor ordenado:\n");
    exibir(Entrada, n);

    return 0;
}
