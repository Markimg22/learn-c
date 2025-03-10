> ## Modificadores:

Alguns tipos podem ser modificados com <kbd>signed</kbd>, <kbd>unsigned</kbd>, <kbd>short</kbd> e <kbd>long</kbd> para alterar o intervalo de valores.

Exemplo: <kbd>unsigned int</kbd>, <kbd>long long int</kbd>

**Signed vs Unsigned**
| Tipo          | Descrição |
|:-------------:|:----------|
| signed        | Permite armazenar valores negativos e positivos, é o padrão caso não especifique |
| unsigned      | Apenas valores positivos (zero ou maior), aumenta a faixa de valores positivos |

---

**Outos Modificadores**

| Tipo  | Intervalo (<kbd>signed</kbd>) | Intervalo (<kbd>unsigned</kbd>) |
|:-----:|:-----------------------------:|:-------------------------------:|
| short | (2 bytes) -32.768 a 32.767    | 0 a 65.535                      |
| long  | (8 bytes) Depende do Sistema  | Depende do Sistema              |

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    unsigned int valores_positivos = 12;
    printf("Numeros positivos: %d\n", valores_positivos);

    long double age_of_universe = 1000000000.1231233L;
    printf("%Lf\n", age_of_universe);

    return 0;
}
```
