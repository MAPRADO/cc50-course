#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Solicite o valor inicial da população ao usuário
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Solicite o valor final da população ao usuário
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calcule o número de anos até o valor final da população
    int total = start; //Total é soma incremental da população ano a ano
    int years = 0;
    while (total < end)
    {
        total += (total / 3) - (total / 4);
        years++;
    }

    // TODO: Imprima o número de anos para atingir o valor final da população
    printf("Years: %i\n", years);
}