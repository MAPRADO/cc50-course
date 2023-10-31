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
    while (alt < 0 || alt > 8);

    // Definir o laço para as linhas
    for (int l = 0; l < alt; l++)
    {
        // Espaços em branco ou colunas
        for (int j = alt - 1; j > l; j--)
        {
            printf(" ");
        }

        // Hash's ou blocos da pirâmide
        for (int j = 0; j <= l; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}