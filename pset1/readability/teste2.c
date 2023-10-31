// Cálculo para contar os caracteres - Mas ele não exclue os espaços e pontuação.
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Saída:\n");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        i+= n - '\0';
        printf("%d\n", i);
    }
}