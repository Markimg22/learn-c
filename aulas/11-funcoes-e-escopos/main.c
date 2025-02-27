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
