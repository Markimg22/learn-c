#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    char *full_name = (char *)malloc(sizeof(char));

    if (full_name == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    printf("Digite seu nome completo, digite ENTER ao terminar:\n");

    return 0;
}
