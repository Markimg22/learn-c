#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    /* Capturar strings de tamanhos únicos */
    // char name[100];
    // printf("Digite seu primeiro nome:\n");
    // scanf("%99s", name);
    // printf("Bem-vindo(a) %s\n", name);

    /* Utilizando o 'getline' para alocar um tamanho dinâmico na memória */
    char *full_name = NULL;
    size_t size_full_name = 0;

    printf("Digite seu nome completo:\n");
    ssize_t full_name_caracteres = getline(&full_name, &size_full_name, stdin);

    if (full_name_caracteres != -1) {
        printf("Bem-vindo(a) %s\n", full_name);
    } else {
        printf("Erro ao ler a entrada\n");
    }

    free(full_name); // função "free" de "stdlib" para liberar a memória alocada

    return 0;
}
