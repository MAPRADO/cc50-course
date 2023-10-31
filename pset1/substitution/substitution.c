#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Receber um argumento de linha de comando
int main(int argc, string argv[])
{
    // Não receber sem argumento de linha de comando ou com mais de um argumento
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Definir a string Key
    string key = argv[1];
    /* int leng = 0;
    leng = strlen(key);

    // Verificar o comprimento do argumento versão minha, ok.
    char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alpha = 0;
    alpha = strlen(str1);

    if (leng != alpha)
    {
        printf("KEY must contain 26 characters.\n");
        return 1;
    } */

    //Verificar o comprimento versão de referencia
    if (strlen(key) != 26)
    {
        printf("KEY must contain 26 characters.\n");
        return 1;
    }

    // Verificar se os argumentos são carateres alfabéticos
    int i;
    for (i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("KEY must only contain alphabetic characters.\n");
            return 1;
        }
    }

    //Verificar se não tem caracteres alfabéticos repetidos
    for (i = 0; i < strlen(key); i++)
    {
        int j;
        for (j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("KEY must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    //Solicitar um plaintext ao usuário
    string plaintext = get_string("plaintext: ");

    //Converter todo o alfabeto da KEY em maiusculas
    for (i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[1] - 32;
        }
    }
    //Imprimir o ciphertext
    printf("ciphertext: ");

    for (i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
