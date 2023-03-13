// Encontrar palíndromos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void inverte(char word[], char reversed[]);

void removerpontos(char* str);

int main(int argc, char* argv[]) 
{
    FILE* fp;
    char word[20];
    char invertida[20];
    int count = 0;

// Verifica sintaxe e ficheiro
    if (argc != 2) 
    {
        printf("\n A sintaxe do programa é: Ana.exe %s [ficheiro] \n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("Não foi possível abrir o ficheiro, verificou a sintaxe? ou o ficheiro %s corrompido\n ", argv[1]);
        return 1;
    }
// ------


// Inicio da leitura  
    while (fscanf(fp, "%s", word) == 1) 
    {
        if (strlen(word) >= 3 && strlen(word) <= 10)  // imposta a limitação conforme enunciado
        {
            removerpontos(word); // Descritivo da função e fundamento abaixo.
            inverte(word, invertida);

            if (strcmp(word, invertida) == 0) //compara ambas 
            {
                printf("Encontramos %s \n", word);
                count++;
            }
        }
    }

    printf("Foram encontrados %d palavras palindromas.\n", count);

    fclose(fp);

    return 0;
}
//---------


void inverte(char word[], char reversed[])  // invertemos a string
{
    int i, j;
    for (i = strlen(word) - 1, j = 0; i >= 0; i--, j++) 
    {
        reversed[j] = word[i];
    }
    reversed[j] = '\0';
}


void removerpontos(char* str) // foi necessário criar uma função remover as pontuações Ex: eles. ou papa. estas palavras apesar de polidromas contendo pontuações seria excluidas
{
    int len = strlen(str);
    int j = 0;
    int i;
    
    for ( i = 0; i < len; i++)
    {
        if (!ispunct(str[i]))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}