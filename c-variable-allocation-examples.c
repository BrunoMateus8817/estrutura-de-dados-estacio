#include <stdio.h>

// Variável global, alocação estática
static int a = 0;

void incrementa(void)
{
    // Variável local, alocação automática
    int b = 0;

    // Variável local, alocação estática
    static int c = 0;

    printf("a: %d, b: %d, c: %d\n", a, b, c);

    // Incrementa valores
    a++;
    b++;
    c++;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
        incrementa();

    // Para pausar no Windows, opcional
    // system("pause");

    return 0;
}
