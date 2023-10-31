#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// Pontos atribuídos a cada letra do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    // Receber palavras de entrada de ambos os jogadores
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    // Pontuação de ambas as palavras
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Comparative the player 1 with player 2
    // Comparar o jogador 1 com jogador 2
    // TO DO: Print the winner
    // A FAZER: Imprimir o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TO DO: Compute and return score for string
    // A FAZER: Calcular e retornar a pontuação para a string
    int position = 0;
    int value = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (islower(word[i]))
        {
            word[i] = word[i] - 32;
        }

        if (!isalpha(word[i]))
        {
            word[i] = 0;
        }

        position = (word[i] - 65);
        value += POINTS[position];
    }
    return (value);
}