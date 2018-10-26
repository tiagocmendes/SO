#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    
    if(argc != 4)
    {
        fprintf(stderr, "Número de argumentos inválido! (%d)\n",argc);
        return EXIT_FAILURE;
    }

    double x1 = atof(argv[1]);
    double x2 = atof(argv[3]);
    //char op = argv[2][0];
    char op = *argv[2];
    double i;   

    switch(op)
    {
        case '+':
            i = x1 + x2;
            printf("%.3f + %.3f = %.3f\n",x1,x2,i);
            break;
        case '-':
            i = x1 - x2;
            printf("%.3f - %.3f = %.3f\n",x1,x2,i);
            break;
        case 'x':
            i = x1 * x2;
            printf("%.3f * %.3f = %.3f\n",x1,x2,i);
            break;
        case '/':
            i = x1 / x2;
            printf("%.3f / %.3f = %.3f\n",x1,x2,i);
            break;
        case 'p':
            i = pow(x1,x2);
            printf("%.3f ** %.3f = %.3f\n",x1,x2,i);
            break;
        default:
            printf("Operação não encontrada!");
            break;
    }

    return EXIT_SUCCESS;
}