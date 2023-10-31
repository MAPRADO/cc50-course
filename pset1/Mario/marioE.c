#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int alt;
    do
    {
        alt = get_int("Que altura você deseja? ");
    } while (alt < 0 || alt > 8);

    for (int l = alt; l > 0 && l < 9; l--)
    {
        for (int c = alt; c > 0 && c < 9; c--)
        {
            printf("%c.", c);

            for (int r = alt; r > 0 && r < 9; r++)
            {
                printf("%c#", r);
            }
        }
        printf("\n");
    }
}