> # Passagem por Referência, Parâmetro de Função:
Caso não queira passar um parâmetro por cópia, mas sim, por **referência** .
Passagem por referência é passar a posição na memória.

```c
#include <stdio.h>

void dobrar(int *num) {
    *num *= 2; // Modifica diretamente o valor na memória
}

int main() {
    int valor = 10;
    printf("Valor antes: %d\n", valor); // 10
    dobrar(&valor);
    printf("Valor depois: %d\n", valor); // 20

    return 0;
}
```
