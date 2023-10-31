#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cartao = 0;
    long digitos;
    int num_digitos = 0;

    //Entrada do usuário número do cartão
    cartao = get_long("Cartão nº: ");
    digitos = cartao;
    num_digitos = 0;

    //Conta quantos dígitos o número do cartão possui
    while (digitos > 0)
    {
        digitos = round(digitos / 10);
        num_digitos++;
    }

    //Pegar os digitos pares e impares, somá-los de acordo com o Algoritmo
    //de Luhn. (num = o número que se está lendo; somapar = soma dos pares;
    //somaimpar = soma do impares; epar = dirá se é par ou impar). PS: sempre
    //da direita p/ esquerda
    int num;
    int somapar = 0;
    int somaimpar = 0;
    int epar = 0;
    int num_iniciais;

    //Vai fazer a varredura dos números do cartão da direita para a esquerda
    while (cartao > 0)
    {
        num = cartao % 10;
        epar++;
        cartao = cartao / 10;
        //Se o número for par então a divisão por 2 não terá resto
        if (epar % 2 == 0)
        {
            num *= 2;
            //Se for maior do que 10 então precisará separar os algarismos para
            //somá-los
            if (num >= 10)
            {
                num = (num % 10) + (num / 10);
                somapar += num;
            }
            else
            {
                somapar += num;
            }
        }
        else
        {
            somaimpar += num;
        }

        //Checar quais são os dois primeiros digitos do cartão
        if (cartao < 100 && cartao >= 10)
        {
            num_iniciais = cartao;
        }
    }

    //Verifica se atende ao Algoritmo de Luhn e se tem entre 12 à 19 dígitos
    if (((somapar + somaimpar) % 10) == 0 && num_digitos >= 12 && num_digitos <= 19)
    {
        //American Express (34 e 37)
        if (num_iniciais == 34 || num_iniciais == 37)
        {
            printf("AMEX\n");
        }
        //MasterCard (51 à 55)
        else if (num_iniciais >= 51 && num_iniciais <= 55)
        {
            printf("MASTERCARD\n");
        }
        //Visa (4)
        else if (num_iniciais / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
