> # Strings

Para trabalhar com strings no C, você pode utilizar um array de caracteres ou ponteiros.

**Array de Caracteres:**
```c
char name[] = "Marcos";
printf("%s\n", name);

strcpy(name, "Campos"); // Muda a 'string' completa com o strcpy
printf("%s\n", name);
```

**Ponteiros:**

```c
char *name = "Marcos";
printf("%s\n", name);

name[0] = "T"; // ❌ Erro: string literais são imutáveis
```
