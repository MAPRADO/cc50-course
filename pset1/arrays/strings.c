#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf ("Saída: \n");
    int n = 0;
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        printf ("%c\n", s[i]);
    }
}