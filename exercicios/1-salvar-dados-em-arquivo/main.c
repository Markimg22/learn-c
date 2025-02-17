/*
    Crie um programa que receba informações via terminal e salve em um arquivo .txt
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char content[100];

    printf("Insira alguma informação: \n");
    scanf("%99[^\n]", content);

    FILE *file;
    file = fopen("file.txt", "a");

    if (file == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fprintf(file, "%s\n", content);
    fclose(file);

    printf("Arquivo salvo com sucesso!\n");

    return 0;
}
