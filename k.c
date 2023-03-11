// Programa para converter Números romanos em decimais.

#include <stdio.h>
#include <string.h>

int corresponde(char a);

int main(void)
{
    int i, fnum = 0; // inicializa a váriavel fnum a zero
    char x[100];
    printf("Inserir número romano: ");
    scanf("%s", x);
    for (i = 0; i < strlen(x); i++)
    {
        if (corresponde(x[i]) == 0) // Verifica a validade do número romano introduzido, usando a função corresponde caso qualquer caracter diferente de M,D,C,L,X,V,I retorna 0 validando a assim o valor inserido pelo utilizador.
            {
                printf(" Número introduzido invalido, a númeraçao romana aceita apenas os seguintes caracteres: M,D,C,L,X,V e I ");
                return 0;
            }
        if (corresponde(x[i]) >= corresponde(x[i+1])) // Permite solucionar o problema de IV e IX, comparando com o x[i] + 1, se for maior incremanta caso contrário subtrai a fnum.
            fnum += corresponde(x[i]);
        else
            fnum -= corresponde(x[i]); 
    }

    printf("O número inteiro é: %d\n", fnum);
    return 0;
}

int corresponde(char a)
{
    int num=0;
    switch (a)
    {
    case 'M': num = 1000; break;
    case 'D': num = 500; break;
    case 'C': num = 100; break;
    case 'L': num = 50; break;
    case 'X': num = 10; break;
    case 'V': num = 5; break;
    case 'I': num = 1; break;
    default: num = 0;  // qualquer valor diferente de M,D,C,L,X,V,I retorna 0 
    
    }
    return num;
}