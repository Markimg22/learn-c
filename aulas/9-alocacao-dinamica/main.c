#include <stdio.h>
#include <stdlib.h>

int main() {
    char *full_name = (char *)malloc(sizeof(char));

    if (full_name == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    int teste;
    scanf("%d", &teste);

    free(full_name);

    return 0;
}
