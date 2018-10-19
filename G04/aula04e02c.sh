#!/bin/bash
source $PWD/functions.sh

if [ $# != 2 ] ; then
    echo "Não foram inseridos 2 argumentos!"
    exit 1;
fi 
checkDigits $1
if (( $? == 2 )) ; then
    echo "O argumento $1 não é um número!"
    exit 1;
fi
checkDigits $2
if (( $? == 2 )) ; then
    echo "O argumento $2 não é um número!"
    exit 1;
fi


#echo "Insira dois números:"
#read n1
#read n2

compareNumbers n1 n2

case $? in  
    0)
        echo "Os números são iguais"
        ;;
    1)
        echo "O número $n1 é maior que o número $n2"
        ;;
    2)
        echo "O número $n1 é menor que o número $n2"
        ;;
esac
