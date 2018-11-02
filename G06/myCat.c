#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 
    int i, lineCounter;

    /* Validate number of arguments */
    if(argc < 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    errno = 0;
    for(i = 1;i < argc;i++)
    {
        fp = fopen(argv[i], "r");
        if(fp == NULL)
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }
        
        printf("Ficheiro %d:\n",i);
        /* read all the lines of the file */
        lineCounter = 1;
        while(fgets(line, sizeof(line), fp) != NULL )
        {   
            if(line[strlen(line) - 1] == '\n')
                line[strlen(line)-1] = '\0';
            printf("%s -> (%d)\n",line,lineCounter);
            lineCounter++;
        }
        fclose (fp);
        printf("%s","\n");
    }
    
    return EXIT_SUCCESS;
}
