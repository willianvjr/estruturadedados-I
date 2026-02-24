#include <stdio.h>

// Função recursiva para calcular Fibonacci
long fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Valor inválido! Digite um número >= 0.\n");
        return 1;
    }

    long resultado = fibonacci(n);

    printf("Fibonacci(%d) = %ld\n", n, resultado);

    return 0;
}