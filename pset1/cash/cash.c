#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash;
    int coins25 = 0;
    int coins10 = 0;
    int coins5 = 0;
    int coins1 = 0;

    // Entrada do valor positivo e float
    do
    {
        cash = get_float("Insert the amount of change: ");
    }
    while (cash <= 0);

    //Converter "float" em "int". O "round" é uma função que retorna
    //o inteiro mais próximo do número passado, como argumento
    int cents = round(cash * 100);

    //Contando as moedas de 25 centavos
    while (cents > 25 || cents == 25)
    {
        cents = cents - 25;
        coins25++;
    }

    //Contando as moedas de 10 centavos
    while (cents > 10 || cents == 10)
    {
        cents = cents - 10;
        coins10++;
    }

    //Contando as moedas de 5 centavos
    while (cents > 5 || cents == 5)
    {
        cents = cents - 5;
        coins5++;
    }

    //Contando as moedas de 1 centavo
    while (cents > 1 || cents == 1)
    {
        cents = cents - 1;
        coins1++;
    }

    printf("%i coins of 25 cents\n", coins25);
    printf("%i coins of 10 cents\n", coins10);
    printf("%i coins of 5 cents\n", coins5);
    printf("%i coins of 1 cents\n", coins1);
    printf("%i necessary coins\n", coins25 + coins10 + coins5 + coins1);

}