#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf ("Argumento ausente\n");
        return 1;
    }
    printf ("Oi %s\n", argv[1]);
    return 0;
}