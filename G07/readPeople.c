#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    Person p[1024];
    int np,new_np,i;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    np = fread(p, sizeof(Person), 1024, fp);

    printf("n pessoas?\n");
    scanf("%d", &new_np);

    /* Write 10 itens on a file */
    for(i = np ; i < new_np ; i++)
    {    
        printf("Pessoa %d:\n",i+1);
        printf("Nome? \n");
        scanf(" %[^\n]", p[i].name); // o espaço branco é um skip whitespace
        printf("Idade? \n");      
        scanf("%d", &p[i].age);
        printf("Altura? \n");
        scanf("%lf", &p[i].height); // %lf - double
        fwrite(&p, sizeof(Person),1,fp); 
    }

    printPersonInfo(p);
    fclose(fp);
    return EXIT_SUCCESS;
}
