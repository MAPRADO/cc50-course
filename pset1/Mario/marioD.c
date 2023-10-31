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
            int pto = 0;
            pto = c - 1;
            printf("%c.", pto);

            int rsh = 0;
            rsh = c - pto;
            printf("%c#", rsh);
        }
        printf("\n");
    }
}