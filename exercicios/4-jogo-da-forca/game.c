#include "game.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char secret_word[SIZE_WORD];
char player_answer[SIZE_WORD];
char wrong_letters[TOTAL_ATTEMPS];

int attemps = 0;

void set_random_secret_word() {
    FILE *file;
    file = fopen("exercicios/4-jogo-da-forca/words.txt", "r");

    if (file == NULL) {
        printf("Banco de palavras não encontrado!\n");
        exit(1);
    }

    int quantity_of_words;
    fscanf(file, "%d", &quantity_of_words);

    srand(time(0));
    int random_number_for_word = rand() % quantity_of_words;
    for (int i = 0; i <= random_number_for_word; i++) {
        fscanf(file, "%s", secret_word);
    }

    fclose(file);
}

void set_player_answer() {
    int size = strlen(secret_word);

    for (int i = 0; i < size; i++) {
        player_answer[i] = '_';
    }

    player_answer[size] = '\0';
}

void welcome_message() {
    printf("/****************/\n");
    printf("/ Jogo da Forca */\n");
    printf("/****************/\n");
}

void draw_hangman() {
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (attemps >= 1 ? '(' : ' '), (attemps >= 1 ? '_' : ' '), (attemps >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (attemps >= 3 ? '\\' : ' '), (attemps >= 2 ? '|' : ' '), (attemps >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (attemps >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (attemps >= 4 ? '/' : ' '), (attemps >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (size_t i = 0; i < strlen(player_answer); i++) {
        printf("%c ", player_answer[i]);
    }
    printf("\n");
}

int letter_already_chosen(char *choisen_letter) {
    for (size_t i = 0; i < strlen(wrong_letters); i++) {
        if (*choisen_letter == wrong_letters[i]) {
            return 1;
        }
    }
    return 0;
}

void check_letter_in_secret_word(char *choisen_letter) {
    int letter_exists = 0;

    for (size_t i = 0; i < strlen(secret_word); i++) {
        if (*choisen_letter == secret_word[i]) {
            player_answer[i] = *choisen_letter;
            letter_exists = 1;
        }
    }

    if (!letter_exists) {
        attemps += 1;
        printf("Letra '%c' não existe na palavra secreta. Suas tentantivas: %d\n", *choisen_letter, attemps);
    }
}

void choose_a_letter() {
    char choisen_letter;
    printf("Qual letra? ");
    scanf(" %c", &choisen_letter);
    choisen_letter = toupper(choisen_letter);

    if (letter_already_chosen(&choisen_letter)) {
        printf("Letra '%c' já foi escolhida! Tente outra letra.\n", choisen_letter);
        return;
    }

    check_letter_in_secret_word(&choisen_letter);
}

int won() {
    for (size_t i = 0; i < strlen(secret_word); i++) {
        if (player_answer[i] != secret_word[i]) {
            return 0;
        }
    }
    return 1;
}

int lost() { return attemps == TOTAL_ATTEMPS; }

void game() {
    welcome_message();

    set_random_secret_word();
    set_player_answer();

    do {
        draw_hangman();
        choose_a_letter();
    } while (!won() && !lost());

    if (won()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else if (lost()) {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", secret_word);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}
