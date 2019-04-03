#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    int x, y, rta, rta1, rta3;
    int long rta4, rta5;
    float rta2;
    char seguir='s';
    int opcion;
    system ("cls");
    do
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular todas las operaciones\n");
        printf("4- Informar resultados\n");

        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
             printf("ingrese numero A:");
             scanf("%d", &x);
            case 2:
               printf("ingrese numero B:");
               scanf("%d", &y);

                break;
            case 3:
                     printf("3. Calcular todas las operaciones\n\n");
                        printf("a) Calcular la suma (%d+%d)\n", x, y);
                        printf("b) Calcular la resta (%d-%d)\n",x, y);
                        printf("c) Calcular la division (%d/%d)\n",x, y);
                        printf("d) Calcular la multiplicacion (%d*%d)\n",x, y);
                        printf("e) Calcular el factorial(%d!) y factorial (%d!)\n\n",x, y);
                        fflush(stdin);
                         printf("desea continuar: s/n ?");
                         scanf("%c", &seguir);
                        break;
            case 4:
                 rta3=multiplicar(x, y);
                                 if (y==0)
        {
                  printf("No es posible dividir por cero: ");
                  scanf("%d", &y);


        }
                 rta2=dividir(x, y);
                 rta1=resta(x, y);
                 rta=suma(x, y);
                 rta4=factorial(x);
                 rta5=factorial(y);
                 printf("4. Informar resultados\n\n");

                         printf("El resultado de  %d+%d es: %d\n", x, y, rta);
                         printf("El resultado de  %d-%d es: %d\n",x, y, rta1);
                         printf("El resultado de  %d/%d es: %.2f\n",x, y, rta2);
                         printf("El resultado de  %d*%d es: %d\n",x, y, rta3);
                         printf("El factorial de  %d es: %ld y El factorial de %d es: %ld\n", x, rta4, y, rta5);
                         fflush(stdin);
                         printf("desea continuar: s/n ?");
                         scanf("%c", &seguir);
                         break;

                  case 5:
                  seguir = 'n';
                break;
        } }while(seguir=='s');
        return 0;
}








