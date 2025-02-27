> # Funções e Arrays
Em C, arrays são passados para funções usando ponteiros, pois o nome de um array decai para um ponteiro para seu primeiro elemento.
Para retornar um array, você deve alocar memória dinamicamente (já que arrays locais não persistem após a função terminar). Aqui estão exemplos práticos:

**Array como parâmetros:**

```c
#include <stdio.h>

void modificar_array(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] *= 2;
    }
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    modificar_array(numeros, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
```

**Arrays como Retorno:**

```c
#include <stdio.h>
#include <stdlib.h>

int *criar_array(int tamanho) {
    int *novo_array = (int *)malloc(tamanho * sizeof(int));
    if (novo_array == NULL) {
        exit(1); // falha na alocação
    }
    for (int i = 0; i < tamanho; i++) {
        novo_array[i] = i * 1;
    }
    return novo_array;
}

int main() {
    int tamanho = 5;
    int *meu_array = criar_array(tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", meu_array[i]);
    }

    free(meu_array); // libera a memória alocada

    return 0;
}
```
