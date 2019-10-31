#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();


    char seguir='s';
    int opcion;
    int flag = 0;

    while (seguir=='s')
    {
        printf("\t\t MENU");
        printf("\n1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2- Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
        printf("\n3- Alta de empleado");
        printf("\n4- Modificar datos de empleado");
        printf("\n5- Baja de empleado");
        printf("\n6- Listar empleados");
        printf("\n7- Ordenar empleados");
        printf("\n8- Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9- Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n\n10-SALIR\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
            system("cls");
        }
        while (opcion<1 || opcion>10);

        switch (opcion)
        {
        case 1:
            controller_loadFromText("data.csv", listaEmpleados);
            flag = 1;
            break;

        case 2:
            controller_loadFromBinary("archivoBinario.bin", listaEmpleados);
            flag = 1;
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            flag = 1;
            break;

        case 4:
            if(flag ==1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 5:
            if(flag ==1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 6:
            if(flag ==1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 7:
            if(flag ==1)
            {
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 8:
            if(flag == 1)
            {
                if(!controller_saveAsText("archivoTexto.csv", listaEmpleados))
                {
                    printf("LISTA GUARDADA EXITOSAMENTE!\n\n");
                }
                else
                {
                    printf("NO SE PUDO GUARDAR LA LISTA\n\n");
                }
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 9:
            if(flag == 1)
            {
                if(!controller_saveAsBinary("archivoBinario.bin", listaEmpleados))
                {
                    printf("LISTA GUARDADA EXITOSAMENTE!\n\n");
                }
                else
                {
                    printf("NO SE PUDO GUARDAR LA LISTA\n\n");
                }
            }
            else
            {
                printf("\n NO EXISTEN EMPLEADOS CARGADOS\n\n");
            }
            break;

        case 10:
            seguir='n';
            break;
        }
    }
    return 0;
}


