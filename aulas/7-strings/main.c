#include <stdio.h>
#include <string.h>

int main() {
    char first_name[] = "Marcos";
    printf("%s\n", first_name);
    strcpy(first_name, "Campos"); // Muda a 'string' completa com o strcpy
    printf("%s\n", first_name);

    char *name = "Marcos";
    printf("%s\n", name);

    // name[0] = "T"; // ❌ Erro: string literais são imutáveis

    return 0;
}
