/*
Jogo da Forca, o computador escolherá, de maneira randômica, uma palavra que está salva em um arquivo de palavras,
e o jogador deve chutar letra por letra, até advinhá-la. Se o jogador chutar 5 letras erradas, ele perde.
Ao final, o computador fornecerá a possibilidade de o usuário inserir uma nova palavra no banco de dados.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void print_array(const char *array) {
    for (size_t i = 0; i < strlen(array); i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void draw_gibbet(int value) {
    switch (value) {
    case 0:
        printf("  _________ \n");
        printf(" |/        |\n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_____     \n");
        break;
    case 1:
        printf("  _________  \n");
        printf(" |/        | \n");
        printf(" |        (_)\n");
        printf(" |           \n");
        printf(" |           \n");
        printf(" |           \n");
        printf(" |           \n");
        printf("_|_____      \n");
        break;
    case 2:
        printf("  _________  \n");
        printf(" |/        | \n");
        printf(" |        (_)\n");
        printf(" |         | \n");
        printf(" |           \n");
        printf(" |           \n");
        printf(" |           \n");
        printf("_|_____      \n");
        break;
    case 3:
        printf("  _________    \n");
        printf(" |/        |   \n");
        printf(" |        (_)  \n");
        printf(" |        \\|/ \n");
        printf(" |             \n");
        printf(" |             \n");
        printf(" |             \n");
        printf("_|_____        \n");
        break;
    case 4:
        printf("  _________    \n");
        printf(" |/        |   \n");
        printf(" |        (_)  \n");
        printf(" |        \\|/ \n");
        printf(" |         |   \n");
        printf(" |             \n");
        printf(" |             \n");
        printf("_|_____        \n");
        break;
    case 5:
        printf("  _________    \n");
        printf(" |/        |   \n");
        printf(" |        (_)  \n");
        printf(" |        \\|/ \n");
        printf(" |         |   \n");
        printf(" |        / \\ \n");
        printf(" |             \n");
        printf("_|_____        \n");
        break;
    default:
        break;
    }
}

int main() {
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n");

    // defini a palavra secreta
    char secret_word[20];
    sprintf(secret_word, "MELANCIA");
    size_t size_of_secret_word = strlen(secret_word);

    // preenche a resposta inicialmente com '_', de acordo com o tamanho da palavra

    char player_answers[size_of_secret_word + 1];
    for (size_t i = 0; i < size_of_secret_word; i++) {
        player_answers[i] = '_';
    }
    player_answers[size_of_secret_word] = '\0';

    // controle de tentativas

    int attemps = 0;
    int total_attemps = 5;

    char wrong_letters[total_attemps];

    // loop principal

    while (true) {
        draw_gibbet(attemps);

        printf("===============================\n");
        print_array(player_answers);

        // pergunta uma letra
        printf("Qual Letra? ");
        char choisen_letter;
        scanf(" %c", &choisen_letter); // colocar espaço antes para o scanf ignorar os caracteres de espaço (/t, /n)
        char choisen_letter_upper = toupper(choisen_letter);

        // verifica se a letra já foi escolhida anteriormente
        if (strchr(wrong_letters, choisen_letter_upper) == NULL) {
            wrong_letters[attemps] = choisen_letter_upper;
        } else {
            printf("----------------------------\n");
            printf("Letra '%c' já foi escolhida! Tente outra letra.\n", choisen_letter_upper);
            printf("Letras escolhidas: ");
            print_array(wrong_letters);
            continue;
        }

        // verifica se a letra escolhida existe na palavra secreta
        if (strchr(secret_word, choisen_letter_upper) == NULL) {
            attemps += 1;

            printf("----------------------------\n");
            printf("Letra '%c' não existe na palavra secreta! Suas tentativas: %d\n", choisen_letter_upper, attemps);

            if (attemps == total_attemps) {
                printf("----------------------------\n");
                draw_gibbet(attemps);
                printf("Suas tentativas acabaram. Você Perdeu!!\n");
                printf("A palavra certa era: %s\n", secret_word);
                break;
            }

            continue;
        } else {
            // preenche a resposta do jogador
            for (size_t i = 0; i < size_of_secret_word; i++) {
                if (choisen_letter_upper == secret_word[i]) {
                    player_answers[i] = choisen_letter_upper;
                }
            }
        }

        // verifica se acertou a palavra secreta
        if (strcmp(player_answers, secret_word) == 0) {
            printf("----------------------------\n");
            print_array(player_answers);
            printf("----------------------------\n");
            printf("    Parabéns você ganhou!!  \n");
            printf("         ___________        \n");
            printf("        '._==_==_=_.'       \n");
            printf("       .-\\:        /-.     \n");
            printf("      | (|:.       |) |     \n");
            printf("       '-|:.       |-'      \n");
            printf("         \\::.      /       \n");
            printf("          '::.   .'         \n");
            printf("             ) (            \n");
            printf("           _.' '._          \n");
            printf("          '-------'         \n");
            break;
        }
    }

    return 0;
}
