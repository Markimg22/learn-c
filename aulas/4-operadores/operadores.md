> # Operadores:

Semelhante a outras linguagens:

**Aritméticos, Atribuição, Comparação, Lógicos, Incremento/Decremento, Ternário etc**

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int x, y;
    printf("Digite um número: \n");
    scanf("%d", &x);
    printf("Digite outro número: \n");
    scanf("%d", &y);
    printf("Soma: %d\n", (x + y));

    int idade;
    printf("Qual sua idade?\n");
    scanf("%d", &idade);
    bool maior_de_idade = idade >= 18;
    printf("Maior idade? %s\n", maior_de_idade ? "true" : "false");

    int z = 10;
    z++;
    printf("%d", z);

    return 0;
}
```
