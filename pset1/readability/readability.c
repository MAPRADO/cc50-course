#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Receber input do usuário.
    string txt = get_string("Digitar uma string de texto: ");
    //printf("%s\n", txt);

    // Contar o número de letras que existem no texto
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(txt); i++)
    {
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z'))
        {
            letters++;
        }

        // Contar o número de palavras que existem no texto
        if (txt[i] == ' ')
        {
            words++;
        }

        //Contar o número de sentenças
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
        {
            sentences++;
        }
    }
    //Print de teste para as contagens
    //printf("%i letters\n", letters);
    //printf("%i words\n", words);
    //printf ("%i sentences\n", sentences);

    //Calcular o índice Coleman-Liau
    float L = (letters  / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Calcular o nível do grau calculado
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
