#include <stdbool.h>
#include <stdio.h>

int main() {
    int idade = 18;
    if (idade >= 18) {
        printf("Maior de idade\n");
    } else {
        printf("Menor de idade\n");
    }

    int valor = 1;
    switch (valor) {
    case 1:
        printf("Valor é 1\n");
        break;
    default:
        break;
    }

    int some_number;
    printf("Insira um número:\n");
    scanf("%d", &some_number);
    int count = 1;
    while (count <= 10) {
        printf("%d x %d = %d\n", count, some_number, (count * some_number));
        count++;
    }

    for (int i = 0; i <= 10; i++) {
        printf("%i\n", i);
    }

    return 0;
}
