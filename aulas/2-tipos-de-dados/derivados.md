> ## Tipos Derivados:

> ### Array

```c
int main(int argc, char const *argv[]) {
    // 4 bytes * 7 posições = 28 bytes
    int array_of_numbers[7] = {1, 2, 3, 4, 5, 6, 10};

    // 3 bytes * 10 posições = 30 bytes
    char tasks[3][10] = {"Estudar", "Ler", "Trabalhar"};

	char name[100] = "Marcos";

    return 0;
}
```

> ### Struct
Uma <kbd>struct</kbd> permite agrupar múltiplas variáveis de diferentes tipos sob um único nome. Cada membro da estrutura ocupa seu próprio espaço na memória.

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    struct person {
        char name[20];
        int age;
    };

    struct person person_1 = {"Marcos", 24};

    printf("%s\n", person_1.name);
    printf("%d\n", person_1.age);

    return 0;
}
```

> ### Union
Uma <kbd>union</kbd> é semelhante a um struct, mas seus membros compartilham o mesmo espaço de memória, isso significa que a união ocupa apenas o tamanho do maior membro.

> ### Enum

> ### Pointer
É uma variável que armazena o endereço me memória de outra variável

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int year, *p_year;

    year = 2025;
    p_year = &year; // armazena o endereço de 'year'

    printf("%d\n", *p_year); // O '*' pega o conteúdo do ponteiro, ou seja, o conteúdo da variável que ele está apontando
    printf("%d\n", *&year);  // mesma coisa, pois o '&' pega o endereço de memória, e o '*' pega o conteúdo daquela memória

    printf("%p\n", &year);  // pega o endereço de 'year' em memória
    printf("%p\n", p_year); // é o endereço de 'year'

    printf("%p\n", &p_year); // é o endereço de 'p_year';

    return 0;
}
```
