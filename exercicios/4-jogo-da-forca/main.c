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

void draw_hangman(int value) {
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
        printf("Valor inválido.\n");
        break;
    }
}

void initialize_player_answer(char *player_answer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        player_answer[i] = '_';
    }
    player_answer[size] = '\0';
}

void fill_player_answer(char *player_answer, char *secret_word, char *choisen_letter, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (*choisen_letter == secret_word[i]) {
            player_answer[i] = *choisen_letter;
        }
    }
}

void ask_for_a_letter(char *choisen_letter) {
    printf("Qual Letra? ");
    scanf(" %c", choisen_letter); // colocar espaço antes para o scanf ignorar os caracteres de espaço (/t, /n)
    *choisen_letter = toupper(*choisen_letter);
}

void welcome_message() {
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n");
}

bool check_if_letter_already_chosen(char *wrong_letters, char *choisen_letter, int attemps) {
    if (strchr(wrong_letters, *choisen_letter) == NULL) {
        wrong_letters[attemps] = *choisen_letter;
        return false;
    } else {
        printf("----------------------------\n");
        printf("Letra '%c' já foi escolhida! Tente outra letra.\n", *choisen_letter);
        printf("Letras escolhidas: ");
        print_array(wrong_letters);
        return true;
    }
}

void game() {
    welcome_message();

    char secret_word[20];
    sprintf(secret_word, "MELANCIA");
    size_t size_of_secret_word = strlen(secret_word);

    char player_answer[size_of_secret_word + 1];
    initialize_player_answer(player_answer, size_of_secret_word);

    int attemps = 0;
    int total_attemps = 5;

    bool won = false;
    bool lost = false;

    char wrong_letters[total_attemps];

    while (!won && !lost) {
        draw_hangman(attemps);

        printf("===============================\n");
        print_array(player_answer);

        char choisen_letter;
        ask_for_a_letter(&choisen_letter);

        int letter_already_chosen = check_if_letter_already_chosen(wrong_letters, &choisen_letter, attemps);
        if (letter_already_chosen) {
            continue;
        }

        if (strchr(secret_word, choisen_letter) == NULL) {
            attemps += 1;
            printf("----------------------------\n");
            printf("Letra '%c' não existe na palavra secreta! Suas tentativas: %d\n", choisen_letter, attemps);
        } else {
            fill_player_answer(player_answer, secret_word, &choisen_letter, size_of_secret_word);
        }

        if (attemps == total_attemps) {
            lost = true;
        }

        if (strcmp(player_answer, secret_word) == 0) {
            won = true;
        }
    }

    if (won) {
        printf("----------------------------\n");
        print_array(player_answer);
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
    } else if (lost) {
        printf("----------------------------\n");
        draw_hangman(attemps);
        printf("Suas tentativas acabaram. Você Perdeu!!\n");
        printf("A palavra certa era: %s\n", secret_word);
    }
}

int main() {
    game();
    return 0;
}
