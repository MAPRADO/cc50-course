#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Receber argumento de linha de comando
int main(int argc, char *argv[])
{
    // Não receber sem argumento de linha de comando ou com mais de um argumento
    if (argc != 2)
    {
        printf("Argumento ausente ou excedente\n");
        return 1;
    }
    // Definir a string Key
    string key = argv[1];

    // Verificar se o argumento é um dígito decimal
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }

    // Converter o argumento da linha de comando, de uma string para int
    int k = atoi(key);

    // Digitar um texto simples para ser criptografado
    string text = get_string("Plaintext: ");

    // Fazer a rotação das letras utilizando a Key recebida pelo argumento
    // na linha de comando e obter o Ciphertext

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", (((text[i] - 65) + k) % 26) + 65);
        }
        else if (islower(text[i]))
        {
            printf("%c", (((text[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
