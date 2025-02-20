#include <stdio.h>

int main() {
    long long int number;
    printf("Digite um número: \n");
    scanf("%lld", &number);

    // calcular o fatorial
    // !5 = 5 * 4 * 3 * 2 * 1 = 120
    printf("!%lld = ", number);
    long long int fatorial = 1;
    for (int i = number; i > 0; i--) {
        if (i == 1) {
            printf("%d = ", i);
        } else {
            printf("%d x ", i);
        }

        fatorial *= i;
    }

    printf("%lld\n", fatorial); // Fatorial de números muito grande, como 120, não funciona, precisará de libs como o GMP

    return 0;
}
