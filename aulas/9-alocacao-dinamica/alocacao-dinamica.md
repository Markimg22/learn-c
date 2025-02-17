> # Alocação Dinâmica:

Permite definir o tamanho de dados em tempo de execução, permite criar estruturas flexíveis (como listas, árvores) e economizar memória. Para isso existe algumas funções principais.

> ## malloc():
Memory Allocation (Alocação de Memória), uma biblioteca padrão da linguagem C, definida no cabeçalho <kbd><stdlib.h></kbd>, utilizado para alocar dinamicamente memória duraten a execução do programa.

Ela recebe como parâmetro a quantidade de bytes que precisa ser alocado, e nos devolve um ponteiro para o primeiro byte alocado.

```c
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size) {
    printf("[");

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Digite o tamanho do array:\n");
    scanf("%d", &n);

    // Aloca a memória para 'n' inteiros
    int *arr = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (arr == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

    // Preenche o array
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    print_array(arr, n);

    // Libera a memória alocada
    free(arr);

    return 0;
}
```

> ## realloc():
Reallocate Memory (Realocação de Memória), redimensiona um bloco de memória previamente alocado. Ela pode diminuir, aumentar, mover etc. Ela recebe o ponteiro original e o novo tamanho em bytes.

```c
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(int argc, char const *argv[]) {
    int *original_array_of_numbers;
    int original_size;

    // Passo 1: solicitar o tamanho inicial do array
    printf("Digite o tamanho original do array:\n");
    scanf("%d", &original_size);

    // Passo 2: aloca a memória para o array
    original_array_of_numbers = (int *)malloc(original_size * sizeof(int));

    // verifica se a alocação foi bem-sucedida
    if (original_array_of_numbers == NULL) {
        printf("Erro na alocação de memória\n");
        return 1;
    }

    // Passo 3: preenche o array com valores
    for (int i = 0; i < original_size; i++) {
        original_array_of_numbers[i] = i;
    }

    // Passo 4: imprimi o array original
    print_array(original_array_of_numbers, original_size);

    // Passo 5: redimensiona o array para o dobro do tamanho
    int new_size;
    printf("Digite o novo tamanho do array:\n");
    scanf("%d", &new_size);

    int *new_array_of_numbers = (int *)realloc(original_array_of_numbers, new_size * sizeof(int));

    // Verifica se a realocação foi bem-sucedida
    if (new_array_of_numbers == NULL) {
        printf("Erro na realocação de memória\n");
        free(original_array_of_numbers); // libera a memória original antes de sair
        return 1;
    } else {
        original_array_of_numbers = new_array_of_numbers; // atualiza o ponteiro para o novo bloco
    }

    // Passo 6: preenche os novos espaços no array
    for (int i = 0; i < new_size; i++) {
        original_array_of_numbers[i] = i;
    }

    // Passo 7: imprimir o array redimensionado
    print_array(original_array_of_numbers, new_size);

    // Passo 8: libera a memória alocada
    free(original_array_of_numbers);
    original_array_of_numbers = NULL; // boa prática: define o ponteiro como NULL após liberar

    return 0;
}
```

> ## free():
