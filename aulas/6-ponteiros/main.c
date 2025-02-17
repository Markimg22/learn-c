#include <stdio.h>

int main() {
    int x = 42;
    printf("conteudo de x: %d\n", x);                          // 42
    printf("endereço de x: %p\n", &x);                         // endereço de 'x' em memória (ex.: 0x16f8ae7bc)
    int *ponteiro = &x;                                        // 'ponteiro' aponta para o endereço de 'x' em memória
    printf("conteudo apontado por ponteiro: %d\n", *ponteiro); // 42
    printf("endereço apontado por ponteiro: %p\n", ponteiro);  // 0x16f8ae7bc
    printf("endereço do ponteiro: %p\n", &ponteiro);           // endereço de 'ponteiro' em memória (ex.: 0x16f8ae7b0)
    *ponteiro = 14;                        // muda o conteúdo apontado por ponteiro, ou seja, muda o valor de 'x'
    printf("novo conteudo de x: %d\n", x); // 14

    return 0;
}
