#include <stdio.h>
#include <stdlib.h>

int main() {
    // usando calloc() para alocar um array de 10 inteiros, todos iniciados em 0
    int *array = calloc(10, sizeof(int));

    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    free(array);

    return 0;
}
