#include <stdio.h>
#include <string.h>

int corresponde(char a);

int main(void)
{
    int i, fnum = 0;
    char x[100];
    printf("Inserir número romano: ");
    scanf("%s", x);
    for (i = 0; i < strlen(x); i++)
    {
        if (corresponde(x[i]) >= corresponde(x[i+1]))
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
    default: num = 0;
    
    }
    return num;
}