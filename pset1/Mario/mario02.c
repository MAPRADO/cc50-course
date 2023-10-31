#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Solicitar a altura da pirâmide ao usuário
        // O programa só deve receber números inteiros entre 0 e 8
        height = get_int("Que altura você deseja? ");
    } while (height < 1 || height > 8);

    // Definir o laço para as linhas
    for (int lines = height; lines > 0; lines--)
    {
        // Formando a piramide da esquerda
        for (int bloc = 1; bloc <= height; bloc++)
        {
            if (lines > bloc)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        // Forma os espaços entre a piramides
        printf("  ");
            // Formando a piramide da direita
            for (int bloc2 = height; bloc2 > 0; bloc2--)
        {
            if (lines < bloc2 || lines == bloc2)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}