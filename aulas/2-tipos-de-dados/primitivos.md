> ## Tipos Primitivos:

|  Tipo  |  Tamanho | Descrição |
|:------:|:--------:|:---------|
| char   | 1 byte   | Armazena uma caractere ASCII/Unicode |
| int    | 4 bytes  | Número inteiro |
| float  | 4 bytes  | Número de ponto flutuante de precisão simples |
| double | 8 bytes  | Número de ponto flutuante de precisão dupla |

```c
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int idade = 10;
    char sexo = 'M';
    float altura = 1.80;
    bool maior_de_idade = false;
    printf("Idade: %d\n", idade);
    printf("Sexo: %c\n", sexo);
    printf("Altura: %.2f\n", altura);
    printf("Maior de idade: %d\n", maior_de_idade);

    long double numero_decimal_longo = 1231413.1231;
    printf("Numero longo: %Lf\n", numero_decimal_longo);

    unsigned int valores_positivos = 12;
    printf("Numeros positivos: %d\n", valores_positivos);

    return 0;
}
```
