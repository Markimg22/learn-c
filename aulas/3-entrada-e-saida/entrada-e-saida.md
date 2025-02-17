> # Entrada (Input) e Saída (Output)

Funções da biblioteca padrão do C <kbd>stdio.h</kbd>.

Especificadores de formatos:

| Especificador | Tipo de Dado | Exemplo |
|:---:|:---:|:---|
| %d | int (decimal com sinal) | printf("%d", -10); → -10 |
| %f | float ou double (ponto flutuante) | printf("%f", 3.14); → 3.140000 |
| %u | unsigned int (decimal sem sinal) | printf("%u", 10); → 10 |
| %c | char (caractere único) | printf("%c", 'A'); → A |
| %s | char* (string) | printf("%s", "Olá!"); → Olá! |
| %x | int (hexadecimal minúsculo) | printf("%x", 255); → ff |
| %X | int (hexadecimal maiúsculo) | printf("%X", 255); → FF |
| %o | int (octal) | printf("%o", 10); → 12 |
| %p | Ponteiro (endereço de memória) | printf("%p", &x); → 0x7ffde2b5 |

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    /* Capturar strings de tamanhos únicos */
    char name[100];
    printf("Digite seu primeiro nome:\n");
    scanf("%99s", name);
    printf("Bem-vindo(a) %s\n", name);

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

```
