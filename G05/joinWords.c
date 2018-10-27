#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i, j, numChars;
    char *sentence;

    if(argc == 1)
    {
        printf("Apenas foi introduzido um argumento!");
        EXIT_FAILURE;
    }

    numChars = 0;
    for(i = 1 ; i < argc ; i++)
    {
        for(j = numChars;j < strlen(argv[i]);j++)
        {
            sentence[j] = argv[i][j];
        }
        numChars += strlen(argv[i]);
    }

    printf("Sentence: ");
    for(i = 0; i < strlen(sentence);i++)
    {
        printf("%d%s",sentence[i],(i == strlen(sentence) - 1) ? "\n" : "");
    }
}