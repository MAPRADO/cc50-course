#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int alt;
    do
    {
        // Solicitar a altura da pirâmide ao usuário
        // O programa só deve receber números inteiros entre 0 e 8
        alt = get_int("Que altura você deseja? ");
    }
    while (alt < 1 || alt > 8);

    // Definir o laço para as linhas
    for (int l = 0; l < alt; l++)
    {
        // Definir as colunas
        for (int j = 0; j < alt; j++)
        {
            if (l + j < alt - 1)
            printf(" ");
            else
            printf("#");
        }
        printf("\n");
    }
}