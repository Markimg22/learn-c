> # Funções e Escopos:

1. **Escopo Local** (Variáveis dentro de funções ou blocos {})
2. **Escopo Global** (Variáveis declaradas fora de funções)
3. **Escopo Static** (Mantém o valor entre chamadas, mas com acesso restrito)

Escopo Local e Global é tranquilo de entender:

```c
#include <stdio.h>

int global_number = 30;

void my_function()
{
    int number = 20; // Escopo local
    printf("Minha função, número: %d\n", number);
    printf("Minha função, global number: %d\n", global_number);
}

int main(int argc, char const *argv[])
{
    my_function();
    printf("Main, global number: %d\n", global_number);

    // Criar escopos internos
    {
        int teste = 10;
        printf("Teste number: %d\n", teste);
    }

    return 0;
}
```

Agora o <kbd>static</kbd> é um pouco diferente, elas podem ter dois comportamentos diferentes, dependendo de onde são declaradas.


**Dentro de funções:**

```c
#include <stdio.h>

void contador()
{
    static int count = 0;
    printf("Count: %d\n", count);
    count++;
}

int main(int argc, char const *argv[])
{
    contador(); // 0
    contador(); // 1
    contador(); // 2

    return 0;
}
```

**Em variáveis globais (restrito ao arquivo)**
* Impede que outras partes do programa (outros arquivos .c) acessem a variável.
* Protege dados sensíveis ou informações internas de um módulo.

```c
#include <stdio.h>

static int globa_static = 123; // só pode ser acessada neste arquivo

void show_globa_static()
{
    printf("%d\n", globa_static);
}

int main(int argc, char const *argv[])
{
    show_globa_static();

    return 0;
}
```
