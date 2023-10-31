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
        int pto = l;
        pto = pto - 1;
        char txp = (char)pto;
        printf("%c.", txp);

        int rsh = l;
        rsh = rsh - pto;
        char txr = (char)rsh;
        printf("%c#", txr);

        printf("\n");
    }
}