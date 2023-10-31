#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

//Prototype
float media(int quantidade, int array[]);

int main(void)
{
    //Usando uma array "scores"
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Pontuação: ");
    }

    //Imprimir a média
    printf ("Média:%f\n", (float) media(TOTAL, scores));
}
    // Função para calcular a média
float media(int quantidade, int array[])
{
    int soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += array[i];
    }
    return soma / (float) quantidade;
}
