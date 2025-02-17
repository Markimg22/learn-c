#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("##########################################\n");
    printf("#### Bem-vindo ao Jogo de Advinhação! ####\n");
    printf("##########################################\n");

    // definir dificuldade
    int difficulty;
    printf("Qual o nível de dificudade?\n(1) Fácil (2) Médio (3) Difícil\n");
    scanf("%d", &difficulty);

    int total_of_chances;
    switch (difficulty) {
    case 1: // Fácil
        total_of_chances = 10;
        break;
    case 2: // Médio
        total_of_chances = 7;
        break;
    case 3: // Difícil
        total_of_chances = 4;
        break;
    default:
        printf("Digite um valor válido.\n");
        return 1;
    }

    // gerar número aleatório
    // OBS: o rand gera o mesmo número toda vez que o programa for executado, para gerar números aleatórios a cada vez, precisamos
    // definir uma semente, que seria uma variável que entra na fórmula para gerar o número aleatório.
    srand(time(0)); // usando o tempo em segundo para a semente do rand
    int secret_number = (rand() % 100) + 1;

    // capturar alternativas do jogo
    bool player_winner = false;
    int player_score = 1000;
    int player_attemps = 1;

    while (player_attemps <= total_of_chances) {
        printf("-> Tentativa %d de %d\n", player_attemps, total_of_chances);

        int attemp;
        printf("Chute um número: ");
        scanf("%d", &attemp);

        int score_to_lose = abs((attemp - secret_number) / 2); // 'abs' transforma um número inteiro em positivo
        player_score -= score_to_lose;

        if (attemp > secret_number) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else if (attemp < secret_number) {
            printf("Seu chute foi menor do que o número secreto!\n");
        } else {
            player_winner = true;
            break;
        }

        player_attemps++;
    }

    printf("O número secreto era: %d\n", secret_number);

    if (player_winner) {
        printf("Parabéns você acertou!!\n");
        printf("Você fez %d pontos. Até a próxima!\n", player_score);
    } else {
        printf("Você perdeu! Tente novamente!\n");
    }

    return 0;
}
