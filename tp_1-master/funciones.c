
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int resta (int n1, int n2)
{
    int sacar;
    sacar=n1-n2;
    return sacar;
}
int suma(int n1, int n2)
{
    int resp;
    resp=n1+n2;
    return resp;
}

int factorial(int factor)
{
    int resultado;
    if (factor==1)
    {
        return 1;
    }
    resultado = factor * factorial(factor-1);
    return resultado;
}
float dividir (int n1, int n2)
{
    float d;

    if (n2==0)
        {
            printf("error no se puede dividir por 0 reingrese otro numero: ");
            scanf("%d", &n2);
        }
    d=(float)n1/(float)n2;
    return d;
}


int multiplicar (int n1, int n2)
{
    int x;
    x=n1*n2;
    return x;
}
